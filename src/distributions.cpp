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
        constexpr double _beta(double a, double b)
        {
            return std::tgamma(a) * std::tgamma(b) / std::tgamma(a + b);
        }

        unsigned nChoosek(unsigned n, unsigned k)
        {
            if (k > n)
                return 0;
            if (k * 2 > n)
                k = n - k;
            if (k == 0)
                return 1;

            int result = n;
            for (int i = 2; i <= k; ++i)
            {
                result *= (n - i + 1);
                result /= i;
            }
            return result;
        }

        constexpr double normal_pdf(double x, double mu, double sigma) {
            auto p = (1.0 / (sigma * std::sqrt(2* M_2_PI)) ) * (std::exp( (std::pow(x - mu, 2)) / (2.0 * std::pow(sigma, 2)) ) ) ;
            return p;



        };

        constexpr double normal_cdf(double x, double mu, double sigma){
            const auto MLE =  -1.65451;
            auto z = (x - mu) / sigma;
            auto p_cum = 1.0 / (1 + std::exp(MLE * z));
            return p_cum;
        };


        constexpr double poisson_pdf(double lambda, int x){
            return std::exp(-1*lambda) * (std::pow(lambda, x) / factorial(x));
        }

        constexpr double poisson_cdf(double lambda,  int x)
        {
            if (x < 0) {
                throw std::runtime_error("X must be greater than or equal to 0");
            }
            double total = 0.0;
            for (int i = 0; i<=x;i++){
                total +=  std::pow(lambda, i) / factorial(i);
            };
            total *= std::exp(lambda * -1);

            return total;

        }

        constexpr double exponential_pdf(double beta, double x){
            return (1/beta) * std::exp(-1*x / beta);
        }


        constexpr double exponential_cdf(double beta, double x)
        {
            return 1 - std::exp(-1 * x / beta);
        }

        constexpr double beta_pdf(double alpha, double beta, double x){

           return  (1 /_beta(alpha, beta) ) * pow(x, alpha - 1) * pow(1-x, beta - 1);
            

        }

        constexpr double gamma_pdf(double alpha, double beta, double x){
            return (pow(beta, alpha) / std::tgamma(alpha)) * pow(x, alpha - 1) * std::exp(-1 * beta * x);
        }
        double beta_cdf(double alpha, double beta, double x,
                        int steps = 10'000)
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

        // likewise for Gamma: ∫₀ˣ gamma_pdf(t) dt
        double gamma_cdf(double alpha, double beta, double x,
                         int steps = 10'000)
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

        constexpr double binomialpdf(double p, int n, int x)
        {
            if(p > 1 || p < 0){
                throw std::runtime_error("p has to be between 0 and 1");
            }
            if (x < 0 || n<0)
            {
                throw std::runtime_error("X and n must be greater than or equal to 0");
            }
            if (x > n){
                throw std::runtime_error("X must be less than or equal to N");
            }

            return nChoosek(n,x) * std::pow(p,x)* std::pow(1-p, n-x);

        }
    }

}
