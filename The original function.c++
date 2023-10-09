#include <iostream>
#include<Windows.h>

struct Cool
{
public:
    void func()
    {
        std::cout << string<< std::endl;
    }
private:
    const char* string = "hey";
};

Cool* pCool;

int main()
{
    Cool coolstruct;
    pCool = &coolstruct;

    while (true) {
        Sleep(100);
        if (GetAsyncKeyState(VK_END))
        {
            pCool->func();
        }
    }
    
}

