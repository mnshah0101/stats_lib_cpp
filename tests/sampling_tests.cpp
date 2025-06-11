#include <cassert>
#include <vector>
#include <iostream>
#include "stats_lib/stats_lib/sampling.hpp"

int main() {
    // Test invertCdf
    auto cdf = [](double x) { return x * x; }; // Example CDF: F(x) = x^2
    double u = 0.5;
    double sample = stats::sampling::invertCdf(cdf, u);
    assert(std::abs(cdf(sample) - u) < 0.1);

    // Test rejectionSampling
    auto targetPdf = [](double x) { return std::exp(-x); }; // Example target PDF: f(x) = e^(-x)
    auto proposalSample = []() { return stats::RNG().uniformReal(0, 10); }; // Example proposal sample
    auto proposalPdf = [](double x) { return 0.1; }; // Example proposal PDF: g(x) = 0.1
    double c = 2.0;
    double rejectionSample = stats::sampling::rejectionSampling(targetPdf, proposalSample, proposalPdf, c);
    assert(rejectionSample >= 0);

    // Test metropolisHastings
    auto kernel = [](double x) { return x + stats::RNG().normal(0, 1); }; // Example kernel
    double burnIn = 100;
    double x0 = 0.0;
    std::vector<double> mhSamples = stats::sampling::metropolisHastings(1000, targetPdf, kernel, burnIn, x0);
    assert(mhSamples.size() == 1000);

    std::cout << "All tests passed!" << std::endl;
    return 0;
} 