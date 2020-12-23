#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef int (*pFunc)(int,int);

int main() {
    cout << "Start Function ..." << endl;
    HINSTANCE hDll = LoadLibrary("nd.dll");

    if(hDll == NULL) {
        cout << "Load Failed ..." << endl;
        exit(0);
    }

    pFunc pf = (pFunc)GetProcAddress(hDll , "exampleFun");

    if(pf == NULL) {
        cout << "PFunc is null" << endl;
        exit(0);
        
    }

    cout << pf(1,2) << endl;


    FreeLibrary(hDll);
}

