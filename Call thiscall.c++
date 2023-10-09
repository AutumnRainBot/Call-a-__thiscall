#include<Windows.h>

void Main()
{


    //setup the "this pointer" for __thiscall
    void* pointerThis = *(void**)0x15C138;//pthis is a pointer to a pointer since its an address that points to the THIS

    //setup prototyp function for our function
    typedef void(__thiscall* _Func)(void* pThis);


    //setup our actual function that uses __thiscall
    _Func ThisCall = reinterpret_cast<_Func>(0x1510B4);// 0xfffaea1 //0x1aeaffff
    
    //Call the function using thiscall
    ThisCall(pointerThis);

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  reason,
                       LPVOID lpReserved
                     )
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

