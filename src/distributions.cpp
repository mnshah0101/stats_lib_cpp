#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#define _USE_MATH_DEFINES

#include "stats_lib/stats_lib/distribution.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

namespace stats
{



    namespace distributions
    {
        //letes put in  binomial, multinomial, beta, gamme
        double factorial(const int n)
        {
            double f = 1;
            for (int i = 1; i <= n; ++i)
                f *= i;
            return f;
        }

        unsigned nChoosek(unsigned n, unsigned k)
        {
            if (k > n)
                return 0;
            if (k * 2 > n)
                k = n - k;
            if (k == 0)
                return 1;

            unsigned result = n;
            for (unsigned i = 2; i <= k; ++i)
            {
                result *= (n - i + 1);
                result /= i;
            }
            return result;
        }

        double normal_pdf(double x, double mu, double sigma) {
            auto p = (1.0 / (sigma * std::sqrt(2* M_PI)) ) * (std::exp( (std::pow(x - mu, 2)) / (2.0 * std::pow(sigma, 2)) ) ) ;
            return p;
        }

        double beta_cdf(double alpha, double beta, double x, int steps)
        {
            double sum = 0.0;
            double dx = x / steps;
            for (int i = 0; i < steps; ++i)
            {
                double t = (i + 0.5) * dx; // midpoint of [i*dx,(i+1)*dx]
                sum += beta_pdf(alpha, beta, t);
            }
            return sum * dx;
        }

        double gamma_cdf(double alpha, double beta, double x, int steps)
        {
            double sum = 0.0;
            double dx = x / steps;
            for (int i = 0; i < steps; ++i)
            {
                double t = (i + 0.5) * dx;
                sum += gamma_pdf(alpha, beta, t);
            }
            return sum * dx;
        }
    }

}
