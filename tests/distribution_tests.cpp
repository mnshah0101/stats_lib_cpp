#include <cassert>
#include <cmath>
#include <iostream>
#include "stats_lib/stats_lib/distribution.hpp"

int main() {
    // Test factorial
    assert(std::abs(stats::distributions::factorial(5) - 120.0) < 1e-10);
    assert(std::abs(stats::distributions::factorial(0) - 1.0) < 1e-10);

    // Test nChoosek
    assert(stats::distributions::nChoosek(5, 2) == 10);
    assert(stats::distributions::nChoosek(5, 0) == 1);
    assert(stats::distributions::nChoosek(5, 5) == 1);

    // Test normal_pdf
    assert(std::abs(stats::distributions::normal_pdf(0, 0, 1) - 0.3989422804014327) < 1e-10);
    assert(std::abs(stats::distributions::normal_pdf(1, 0, 1) - 0.24197072451914337) < 1e-10);

    // Test normal_cdf
    assert(std::abs(stats::distributions::normal_cdf(0, 0, 1) - 0.5) < 1e-2);
    assert(std::abs(stats::distributions::normal_cdf(1, 0, 1) - 0.8413) < 1e-2);

    // Test poisson_pdf
    assert(std::abs(stats::distributions::poisson_pdf(2, 1) - 0.2706705664732254) < 1e-10);
    assert(std::abs(stats::distributions::poisson_pdf(2, 0) - 0.1353352832366127) < 1e-10);

    // Test poisson_cdf
    assert(std::abs(stats::distributions::poisson_cdf(2, 1) - 0.4060058497098381) < 1e-10);
    assert(std::abs(stats::distributions::poisson_cdf(2, 0) - 0.1353352832366127) < 1e-10);

    // Test exponential_pdf
    assert(std::abs(stats::distributions::exponential_pdf(1, 0) - 1.0) < 1e-10);
    assert(std::abs(stats::distributions::exponential_pdf(1, 1) - 0.36787944117144233) < 1e-10);

    // Test exponential_cdf
    assert(std::abs(stats::distributions::exponential_cdf(1, 0) - 0.0) < 1e-10);
    assert(std::abs(stats::distributions::exponential_cdf(1, 1) - 0.6321205588285577) < 1e-10);

    // Test beta_pdf
    assert(std::abs(stats::distributions::beta_pdf(1, 1, 0.5) - 1.0) < 1e-10);
    assert(std::abs(stats::distributions::beta_pdf(2, 2, 0.5) - 1.5) < 1e-10);

    // Test gamma_pdf
    assert(std::abs(stats::distributions::gamma_pdf(1, 1, 1) - 0.36787944117144233) < 1e-10);
    assert(std::abs(stats::distributions::gamma_pdf(2, 1, 1) - 0.36787944117144233) < 1e-10);

    // Test beta_cdf
    assert(std::abs(stats::distributions::beta_cdf(1, 1, 0.5) - 0.5) < 1e-2);
    assert(std::abs(stats::distributions::beta_cdf(2, 2, 0.5) - 0.5) < 1e-2);

    // Test gamma_cdf
    assert(std::abs(stats::distributions::gamma_cdf(1, 1, 1) - 0.6321205588285577) < 1e-2);
    assert(std::abs(stats::distributions::gamma_cdf(2, 1, 1) - 0.26424111765711533) < 1e-2);

    // Test binomialpdf
    assert(std::abs(stats::distributions::binomialpdf(0.5, 5, 2) - 0.3125) < 1e-10);
    assert(std::abs(stats::distributions::binomialpdf(0.5, 5, 0) - 0.03125) < 1e-10);

    std::cout << "All tests passed!" << std::endl;
    return 0;
} 