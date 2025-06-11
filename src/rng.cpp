#define _USE_MATH_DEFINES

#include "stats_lib/stats_lib/rng.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <exception>
#include <stdexcept>

namespace stats {
    RNG::RNG(unsigned seed) {
        mt = std::mt19937(seed);
    }

    double RNG::uniformReal() {
        return mt() / (double)(std::mt19937::max());
    }

    double RNG::uniformReal(double a, double b) {
            if (a > b){
                throw std::runtime_error("A must be less than b");
            }
        return uniformReal() * (b-a) + a;
    }

    int RNG::uniformInt(int a, int b) {
        return (int)uniformReal(a, b+1);
    }

    bool RNG::bernoulli(double p) {
        if (p < 0 || p > 1) {
            throw std::runtime_error("Probability must be between 0 and 1");
        }
        return uniformReal() < p;
    }

    double RNG::normal(double mu, double sigma) {
        // Box-Muller transform
        auto u1 = uniformReal();
        auto u2 = uniformReal();
        auto z = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
        return mu + sigma * z;
    }

    double RNG::exponential(double lambda) {
        if (lambda <= 0) {
            throw std::runtime_error("Lambda must be positive");
        }
        auto u = uniformReal();
        return -std::log(1.0 - u) / lambda;
    }

    int RNG::binomial(int n, double p) {

        if (p < 0 || p > 1) {
            throw std::runtime_error("Probability must be between 0 and 1");
        }
        if (n < 0) {
            throw std::runtime_error("Number of trials must be non-negative");
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            total += bernoulli(p);
        }
        return total;
    }

    int RNG::poisson(double lambda) {
        if (lambda <= 0) {
            throw std::runtime_error("Lambda must be positive");
        }

        // Direct method for small lambda
        if (lambda < 30) {
            double L = std::exp(-lambda);
            double p = 1.0;
            int k = 0;
            
            do {
                k++;
                p *= uniformReal();
            } while (p > L);
            
            return k - 1;
        } else {
            // For larger lambda, use normal approximation
            double u1 = uniformReal();
            double u2 = uniformReal();
            double z = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
            return static_cast<int>(std::max(0.0, std::round(lambda + std::sqrt(lambda) * z)));
        }
    }
}
