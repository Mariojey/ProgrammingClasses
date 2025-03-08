#ifndef INTEGRATE_H
#define INTEGRATE_H

#ifdef _WIN32
    #ifdef BUILD_INTEGRALS
        #define INTEGRALS_API __declspec(dllexport)
    #else
        #define INTEGRALS_API __declspec(dllimport)
    #endif
#else
    #define INTEGRALS_API
#endif

INTEGRALS_API double integrate(double a, double b, int n, int type);

#endif