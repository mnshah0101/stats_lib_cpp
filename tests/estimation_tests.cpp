#include <cassert>
#include <vector>
#include <iostream>
#include "stats_lib/stats_lib/estimation.hpp"

int main() {
    // Test mleNormal
    std::vector<double> normal_data = {1.0, 2.0, 3.0, 4.0, 5.0};
    auto normal_result = stats::estimation::mleNormal(normal_data);
    assert(std::abs(normal_result.first - 3.0) < 1e-10);
    assert(std::abs(normal_result.second - 2.0) < 1e-10);

    // Test mleExponential
    std::vector<double> exp_data = {1.0, 2.0, 3.0, 4.0, 5.0};
    double exp_result = stats::estimation::mleExponential(exp_data);
    assert(std::abs(exp_result - 0.2) < 1e-10);

    // Test mleBernoulli
    std::vector<double> bernoulli_data = {0.0, 1.0, 1.0, 0.0, 1.0};
    double bernoulli_result = stats::estimation::mleBernoulli(bernoulli_data);
    assert(std::abs(bernoulli_result - 0.6) < 1e-10);

    // Test mleBeta
    std::vector<double> beta_data = {0.1, 0.2, 0.3, 0.4, 0.5};
    auto beta_result = stats::estimation::mleBeta(beta_data);
    assert(std::abs(beta_result.first - 1.5) < 1e-10);
    assert(std::abs(beta_result.second - 3.5) < 1e-10);

    // Test momNormal
    auto mom_normal_result = stats::estimation::momNormal(normal_data);
    assert(std::abs(mom_normal_result.first - 3.0) < 1e-10);
    assert(std::abs(mom_normal_result.second - 2.0) < 1e-10);

    // Test momExponential
    double mom_exp_result = stats::estimation::momExponential(exp_data);
    assert(std::abs(mom_exp_result - 0.2) < 1e-10);

    // Test momBernoulli
    double mom_bernoulli_result = stats::estimation::momBernoulli(bernoulli_data);
    assert(std::abs(mom_bernoulli_result - 0.6) < 1e-10);

    // Test momPoisson
    std::vector<double> poisson_data = {1.0, 2.0, 3.0, 4.0, 5.0};
    double poisson_result = stats::estimation::momPoisson(poisson_data);
    assert(std::abs(poisson_result - 3.0) < 1e-10);

    // Test mleGeneric
    auto logLikelihood = [](const std::vector<double>& params) {
        return -params[0] * params[0] - params[1] * params[1];
    };
    std::vector<double> initial_guesses = {1.0, 1.0};
    std::vector<double> generic_result = stats::estimation::mleGeneric(logLikelihood, normal_data, initial_guesses, 1e-10, 100);
    assert(std::abs(generic_result[0]) < 1e-10);
    assert(std::abs(generic_result[1]) < 1e-10);

    std::cout << "All tests passed!" << std::endl;
    return 0;
} 