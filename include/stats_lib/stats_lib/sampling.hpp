#pragma once

#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#define _USE_MATH_DEFINES

#include <functional>
#include <vector>
#include "stats_lib/stats_lib/rng.hpp"

namespace stats {
    namespace sampling {
        /**
         * @brief Invert a cumulative distribution function to generate samples
         * 
         * @param cdf The cumulative distribution function
         * @param u Uniform random number in [0,1]
         * @return Generated sample
         */
        double invertCdf(const std::function<double(double)>& cdf, double u);

        /**
         * @brief Generate samples using rejection sampling
         * 
         * @param targetPdf Target probability density function
         * @param proposalSample Function to generate samples from proposal distribution
         * @param proposalPdf Proposal probability density function
         * @param c Scaling factor (must be > 1.0)
         * @return Generated sample
         */
        double rejectionSampling(
            const std::function<double(double)>& targetPdf,
            const std::function<double()>& proposalSample,
            const std::function<double(double)>& proposalPdf,
            double c
        );

        /**
         * @brief Generate samples using Metropolis-Hastings algorithm
         * 
         * @param nSamples Number of samples to generate
         * @param targetPdf Target probability density function
         * @param kernel Kernel function for proposal distribution
         * @param burnIn Number of burn-in samples to discard
         * @param x0 Initial state
         * @return Vector of generated samples
         */
        std::vector<double> metropolisHastings(
            const int nSamples,
            const std::function<double(double)>& targetPdf,
            const std::function<double(double)>& kernel,
            double burnIn,
            double x0
        );
    }
}
