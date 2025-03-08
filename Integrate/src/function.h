#ifndef INTEGRATE_FUNCTION
#define INTEGRATE_FUNCTION

#ifdef _WIN32
    #ifdef BUILD_FUNCTION
        #define INTEGRATE_FUNCTION_1 __declspec(dllexport)
        #define INTEGRATE_FUNCTION_2 __declspec(dllexport)
        #define INTEGRATE_FUNCTION_3 __declspec(dllexport)
        #define INTEGRATE_FUNCTION_4 __declspec(dllexport)
    #else
        #define INTEGRATE_FUNCTION_1 __declspec(dllimport)
        #define INTEGRATE_FUNCTION_2 __declspec(dllimport)
        #define INTEGRATE_FUNCTION_3 __declspec(dllimport)
        #define INTEGRATE_FUNCTION_4 __declspec(dllimport)
    #endif
#else
    #define INTEGRATE_FUNCTION_1
    #define INTEGRATE_FUNCTION_2
    #define INTEGRATE_FUNCTION_3
    #define INTEGRATE_FUNCTION_4
#endif

INTEGRATE_FUNCTION_1 double f1(double x);
INTEGRATE_FUNCTION_2 double f2(double x);
INTEGRATE_FUNCTION_3 double f3(double x);
INTEGRATE_FUNCTION_4 double f4(double x);

#endif