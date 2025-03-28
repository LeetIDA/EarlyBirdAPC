```

             _____           _        ______ _         _   _____      _           _
            |  ___|         | |       | ___ (_)       | | |_   _|    (_)         | |
            | |__  __ _ _ __| |_   _  | |_/ /_ _ __ __| |   | | _ __  _  ___  ___| |_ ___  _ __
            |  __|/ _` | '__| | | | | | ___ \ | '__/ _` |   | || '_ \| |/ _ \/ __| __/ _ \| '__|
            | |__| (_| | |  | | |_| | | |_/ / | | | (_| |  _| || | | | |  __/ (__| || (_) | |
            \____/\__,_|_|  |_|\__, | \____/|_|_|  \__,_|  \___/_| |_| |\___|\___|\__\___/|_|
                                __/ |                               _/ |
                               |___/                               |__/


                                Early Bird APC Injector (x86 / x64)
                                   EXE Early Bird APC Injector
```

<p align="center">
    <img src="https://skillicons.dev/icons?i=c" alt="C">
    <img src="https://skillicons.dev/icons?i=windows" alt="Windows">
</p>

## :open_book: Project Overview :

APC injection requires either a suspended or an alertable thread to successfully execute the payload. However, it is difficult to come across threads that are in these states, especially ones that are operating under normal user privileges.

The solution for this is to create a suspended process using the CreateProcess WinAPI and use the handle to its suspended thread. The suspended thread meets the criteria to be used in APC injection. This method is known as Early Bird APC Injection.

This project works in x86 and x64, EXE .

### Early Bird Implementation Logic (1) :

#### The implementation logic of this technique will be as follows:

1. Create a suspended process by using the `CREATE_SUSPENDED` flag.
2. Write the payload to the address space of the new target process.
3. Get the suspended thread's handle from `CreateProcess` along with the payload's base address and pass them to `QueueUserAPC`.
4. Resume the thread using the `ResumeThread` WinAPI to execute the payload.

### Early Bird Implementation Logic (2):

The implementation logic explained in the previous section is straightforward. This section introduces an alternative way of implementing Early Bird APC Injection.

`CreateProcess` will still be used, but the [Process Creation Flag](https://learn.microsoft.com/en-us/windows/desktop/ProcThread/process-creation-flags) will be changed from `CREATE_SUSPENDED` to `DEBUG_PROCESS`.
The `DEBUG_PROCESS` flag will create the new process as a debugged process and make the local process its debugger. When a process is created as a debugged process, a breakpoint will be placed in its entry point. This pauses the process and waits for the debugger (i.e. the malware) to resume execution.

When this occurs, the payload is injected into the target process to be executed using the `QueueUserAPC` WinAPI. Once the payload is injected and the remote debugged thread is queued to run the payload, the local process can be detached from the target process using the [DebugActiveProcessStop](https://learn.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-debugactiveprocessstop) WinAPI which stops the remote process from being debugged.

`DebugActiveProcessStop` requires only one parameter which is the PID of the debugged process that can be fetched from the `PROCESS_INFORMATION` structure populated by `CreateProcess`.

### Updated Implementation Logic :

#### The updated implementation will be as follows:

1. Create a debugged process by setting the `DEBUG_PROCESS` flag.
2. Write the payload to the address space of the new target process.
3. Get the debugged thread's handle from `CreateProcess` along with the payload's base address and pass them to `QueueUserAPC`.
4. Stop the debugging of the remote process using `DebugActiveProcessStop` which resumes its threads and executes the payload.

### Early Bird APC Injection Function :

#### `CreateSuspendedProcess2` is a function that performs Early Bird APC Injection and requires 4 arguments:

- `lpProcessName` - The name of the process to create.
- `dwProcessId` - A pointer to a DWORD which will receive the newly created process's PID.
- `hProcess` - Pointer to a HANDLE that will receive the newly created process's handle.
- `hThread` - Pointer to a HANDLE that will receive the newly created process's thread.

> **⚠ Warning:** This project is for educational purposes only. Misuse of this code for malicious purposes is strictly prohibited and may violate laws and regulations.

<p align="center">
    <img src="https://visitor-badge.laobi.icu/badge?page_id=LeetIDA.EarlyBirdAPC" alt="visitor badge"/>
</p>
