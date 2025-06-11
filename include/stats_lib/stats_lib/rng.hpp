#pragma once

#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>

namespace stats {
    /**
     * @brief Random Number Generator class
     * 
     * Provides methods for generating random numbers from various distributions
     */
    class RNG {
    private:
        std::mt19937 mt;

    public:
        /**
         * @brief Construct a new RNG object
         * 
         * @param seed Seed for the random number generator
         */
        RNG(unsigned seed = std::random_device{}());
        
        /**
         * @brief Generate a uniform random number in [0,1)
         * 
         * @return Random number
         */
        double uniformReal();
        
        /**
         * @brief Generate a uniform random number in [a,b)
         * 
         * @param a Lower bound
         * @param b Upper bound
         * @return Random number
         */
        double uniformReal(double a, double b);
        
        /**
         * @brief Generate a uniform random integer in [a,b]
         * 
         * @param a Lower bound
         * @param b Upper bound
         * @return Random integer
         */
        int uniformInt(int a, int b);

        /**
         * @brief Generate a Bernoulli random variable
         * 
         * @param p Success probability
         * @return 1 with probability p, 0 with probability 1-p
         */
        bool bernoulli(double p);
        
        /**
         * @brief Generate a normal random variable
         * 
         * @param mu Mean
         * @param sigma Standard deviation
         * @return Random number
         */
        double normal(double mu = 0, double sigma = 1);
        
        /**
         * @brief Generate an exponential random variable
         * 
         * @param lambda Rate parameter
         * @return Random number
         */
        double exponential(double lambda);

        /**
         * @brief Generate a Poisson random variable
         * 
         * @param lambda Rate parameter
         * @return Random integer
         */
        int poisson(double lambda);
        
        /**
         * @brief Generate a binomial random variable
         * 
         * @param n Number of trials
         * @param p Success probability
         * @return Random integer
         */
        int binomial(int n, double p);
    };
}
