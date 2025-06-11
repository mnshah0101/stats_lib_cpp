#pragma once

#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>

namespace stats {
    namespace distributions {
        /**
         * @brief Calculate factorial of a number
         * @param n The number to calculate factorial for
         * @return The factorial of n
         */
        double factorial(const int n);

        /**
         * @brief Calculate the beta function B(a,b)
         * @param a First parameter
         * @param b Second parameter
         * @return Value of the beta function
         */
        constexpr double _beta(double a, double b) {
            return std::tgamma(a) * std::tgamma(b) / std::tgamma(a + b);
        }

        /**
         * @brief Calculate binomial coefficient (n choose k)
         * @param n Total number of items
         * @param k Number of items to choose
         * @return Binomial coefficient value
         */
        unsigned nChoosek(unsigned n, unsigned k);

        /**
         * @brief Calculate normal probability density function
         * @param x Value to evaluate
         * @param mu Mean parameter
         * @param sigma Standard deviation parameter
         * @return PDF value
         */
        double normal_pdf(double x, double mu, double sigma);

        /**
         * @brief Calculate normal cumulative distribution function
         * @param x Value to evaluate
         * @param mu Mean parameter
         * @param sigma Standard deviation parameter
         * @return CDF value
         */
        constexpr double normal_cdf(double x, double mu, double sigma) {
            const auto MLE = -1.65451;
            auto z = (x - mu) / sigma;
            auto p_cum = 1.0 / (1 + std::exp(MLE * z));
            return p_cum;
        }

        /**
         * @brief Calculate Poisson probability mass function
         * @param lambda Rate parameter
         * @param x Value to evaluate
         * @return PMF value
         */
        constexpr double poisson_pdf(double lambda, int x) {
            return std::exp(-1*lambda) * (std::pow(lambda, x) / factorial(x));
        }

        /**
         * @brief Calculate Poisson cumulative distribution function
         * @param lambda Rate parameter
         * @param x Value to evaluate
         * @return CDF value
         */
        constexpr double poisson_cdf(double lambda, int x) {
            if (x < 0) {
                throw std::runtime_error("X must be greater than or equal to 0");
            }
            double total = 0.0;
            for (int i = 0; i <= x; i++) {
                total += std::pow(lambda, i) / factorial(i);
            }
            total *= std::exp(lambda * -1);
            return total;
        }

        /**
         * @brief Calculate exponential probability density function
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @return PDF value
         */
        constexpr double exponential_pdf(double beta, double x) {
            return (1/beta) * std::exp(-1*x / beta);
        }

        /**
         * @brief Calculate exponential cumulative distribution function
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @return CDF value
         */
        constexpr double exponential_cdf(double beta, double x) {
            return 1 - std::exp(-1 * x / beta);
        }

        /**
         * @brief Calculate beta probability density function
         * @param alpha First shape parameter
         * @param beta Second shape parameter
         * @param x Value to evaluate
         * @return PDF value
         */
        constexpr double beta_pdf(double alpha, double beta, double x) {
            return (1 / _beta(alpha, beta)) * std::pow(x, alpha - 1) * std::pow(1-x, beta - 1);
        }

        /**
         * @brief Calculate gamma probability density function
         * @param alpha Shape parameter
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @return PDF value
         */
        constexpr double gamma_pdf(double alpha, double beta, double x) {
            return (std::pow(beta, alpha) / std::tgamma(alpha)) * std::pow(x, alpha - 1) * std::exp(-1 * beta * x);
        }

        /**
         * @brief Calculate beta cumulative distribution function
         * @param alpha First shape parameter
         * @param beta Second shape parameter
         * @param x Value to evaluate
         * @param steps Number of steps for numerical integration
         * @return CDF value
         */
        double beta_cdf(double alpha, double beta, double x, int steps = 10'000);

        /**
         * @brief Calculate gamma cumulative distribution function
         * @param alpha Shape parameter
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @param steps Number of steps for numerical integration
         * @return CDF value
         */
        double gamma_cdf(double alpha, double beta, double x, int steps = 10'000);

        /**
         * @brief Calculate binomial probability mass function
         * @param p Success probability
         * @param n Number of trials
         * @param x Number of successes
         * @return PMF value
         */
        constexpr double binomialpdf(double p, int n, int x) {
            if(p > 1 || p < 0) {
                throw std::runtime_error("p has to be between 0 and 1");
            }
            if (x < 0 || n < 0) {
                throw std::runtime_error("X and n must be greater than or equal to 0");
            }
            if (x > n) {
                throw std::runtime_error("X must be less than or equal to N");
            }
            return nChoosek(n,x) * std::pow(p,x) * std::pow(1-p, n-x);
        }
    }
}
