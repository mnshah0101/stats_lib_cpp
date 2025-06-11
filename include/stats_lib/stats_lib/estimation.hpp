#pragma once

#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <functional>
#include <utility>
#include <cmath>
#include <ctime>

namespace stats {
    namespace estimation {
        /**
         * @brief Maximum Likelihood Estimation for Normal distribution
         * @param data Vector of observations
         * @return Pair of estimated mean and variance
         */
        std::pair<double, double> mleNormal(const std::vector<double>& data);

        /**
         * @brief Maximum Likelihood Estimation for Exponential distribution
         * @param data Vector of observations
         * @return Estimated lambda parameter
         */
        double mleExponential(const std::vector<double>& data);

        /**
         * @brief Maximum Likelihood Estimation for Bernoulli distribution
         * @param data Vector of observations
         * @return Estimated probability parameter
         */
        double mleBernoulli(const std::vector<double>& data);

        /**
         * @brief Maximum Likelihood Estimation for Beta distribution
         * @param data Vector of observations
         * @return Pair of estimated alpha and beta parameters
         */
        std::pair<double, double> mleBeta(const std::vector<double>& data);

        /**
         * @brief Method of Moments Estimation for Normal distribution
         * @param data Vector of observations
         * @return Pair of estimated mean and variance
         */
        std::pair<double, double> momNormal(const std::vector<double>& data);

        /**
         * @brief Method of Moments Estimation for Exponential distribution
         * @param data Vector of observations
         * @return Estimated lambda parameter
         */
        double momExponential(const std::vector<double>& data);

        /**
         * @brief Method of Moments Estimation for Bernoulli distribution
         * @param data Vector of observations
         * @return Estimated probability parameter
         */
        double momBernoulli(const std::vector<double>& data);

        /**
         * @brief Method of Moments Estimation for Poisson distribution
         * @param data Vector of observations
         * @return Estimated lambda parameter
         */
        double momPoisson(const std::vector<double>& data);

        /**
         * @brief Generic Maximum Likelihood Estimation using numerical optimization
         * @param logLikelihood Log-likelihood function to maximize
         * @param data Vector of observations
         * @param initial_guesses Initial parameter guesses
         * @param tolerance Convergence tolerance
         * @param max_iterations Maximum number of iterations
         * @return Vector of estimated parameters
         */
        std::vector<double> mleGeneric(
            const std::function<double(const std::vector<double>&)>& logLikelihood,
            const std::vector<double>& data,
            const std::vector<double>& initial_guesses,
            const double& tolerance,
            const int& max_iterations
        );
    }
}
