#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>

namespace stats
{

    class RNG
    {
    private:
        std::mt19937 mt(std::time(nullptr));

    public:
        RNG(unsigned seed = std::random_device{}());
        double uniformReal();                   // [0,1)
        double uniformReal(double a, double b); // [a,b)
        int uniformInt(int a, int b);

        bool bernoulli(double p);
        double normal(double mu = 0, double sigma = 1);
        double exponential(double lambda);

        int poisson(double lambda);
        int binomial(int n, double p);
        // …later: gamma(), beta(), cauchy(), etc.
    };
    }
