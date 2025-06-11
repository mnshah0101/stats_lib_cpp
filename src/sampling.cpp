#define _USE_MATH_DEFINES

#include "stats_lib/stats_lib/sampling.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <exception>
#include <stdexcept>

namespace stats {
    namespace sampling { 
        double invertCdf(const std::function<double(double)>& cdf, double u) {
            double x = 0;
            double y = 0;

            while(y < u){
                y = cdf(x);
                x += 0.001;
            }

            return x;
    

        }
        
        //basically throws away samples that dont fit, so we dont actually need the target cdf
        double rejectionSampling(
            const std::function<double(double)>& targetPdf,
            const std::function<double()>& proposalSample,
            const std::function<double(double)>& proposalPdf,
            double c
        ) {
            if (c <= 1.0){
                throw std::invalid_argument("c must be greater than 1.0");
            }

            stats::RNG rng(std::time(0));
            double x = proposalSample();

            double u = rng.uniformReal(0.00,1.00);


            double fx = targetPdf(x);
            double gx = proposalPdf(x); 

            double alpha = fx * c / gx;

            if (u <= alpha){
                return x;
            } else {
                return rejectionSampling(targetPdf, proposalSample, proposalPdf, c);
            }

        }


        //we only know the kernel not the actual target pdf, so we need to estimate it, burn in are transitory states
        
       //we propose some candidate, we take some sample, then the next sample is normal centered on previous, then we take another and keep going
       //hastings is also asymmetric
       //basically its a stationary markov so we can get to the most likely, pretty much we are just going to the more probable state one by one

       std::vector<double> metropolisHastings(
        const int nSamples,
        const std::function<double(double)>& targetPdf,
        const std::function<double(double)>& kernel,
        double burnIn,
        double x0
       )
       {
        std::vector<double> samples;
        stats::RNG rng(std::time(0));

        double x = x0;
        double u = 0.0;
        double y = 0.0;

        for (int i = 0; i < nSamples + burnIn; i++){
            u = rng.uniformReal(0.0, 1.0);
            y = kernel(x);

            double alpha = std::min(1.0, targetPdf(y) / targetPdf(x));

            if (u <= alpha){
                x = y;
            }

            if (i >= burnIn){
                samples.push_back(x);
            }
        }

        return samples;
       }





    }
}
