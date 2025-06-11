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
        constexpr double _beta(double a, double b);

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
        constexpr double normal_pdf(double x, double mu, double sigma);

        /**
         * @brief Calculate normal cumulative distribution function
         * @param x Value to evaluate
         * @param mu Mean parameter
         * @param sigma Standard deviation parameter
         * @return CDF value
         */
        constexpr double normal_cdf(double x, double mu, double sigma);

        /**
         * @brief Calculate Poisson probability mass function
         * @param lambda Rate parameter
         * @param x Value to evaluate
         * @return PMF value
         */
        constexpr double poisson_pdf(double lambda, int x);

        /**
         * @brief Calculate Poisson cumulative distribution function
         * @param lambda Rate parameter
         * @param x Value to evaluate
         * @return CDF value
         */
        constexpr double poisson_cdf(double lambda, int x);

        /**
         * @brief Calculate exponential probability density function
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @return PDF value
         */
        constexpr double exponential_pdf(double beta, double x);

        /**
         * @brief Calculate exponential cumulative distribution function
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @return CDF value
         */
        constexpr double exponential_cdf(double beta, double x);

        /**
         * @brief Calculate beta probability density function
         * @param alpha First shape parameter
         * @param beta Second shape parameter
         * @param x Value to evaluate
         * @return PDF value
         */
        constexpr double beta_pdf(double alpha, double beta, double x);

        /**
         * @brief Calculate gamma probability density function
         * @param alpha Shape parameter
         * @param beta Scale parameter
         * @param x Value to evaluate
         * @return PDF value
         */
        constexpr double gamma_pdf(double alpha, double beta, double x);

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
        constexpr double binomialpdf(double p, int n, int x);
    }
}
