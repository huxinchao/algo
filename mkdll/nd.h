#ifndef BUILD_ND_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif


extern "C" {
    EXPORT int exampleFun(int,int);
}