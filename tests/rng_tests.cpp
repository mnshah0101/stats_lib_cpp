#include <cassert>
#include <iostream>
#include "stats_lib/stats_lib/rng.hpp"

int main() {
    stats::RNG rng(42); // Fixed seed for reproducibility

    // Test uniformReal
    double u = rng.uniformReal();
    assert(u >= 0.0 && u < 1.0);

    // Test uniformReal(a,b)
    double u_ab = rng.uniformReal(1.0, 5.0);
    assert(u_ab >= 1.0 && u_ab < 5.0);

    // Test uniformInt
    int u_int = rng.uniformInt(1, 10);
    assert(u_int >= 1 && u_int <= 10);

    // Test bernoulli
    bool b = rng.bernoulli(0.5);
    assert(b == 0 || b == 1);

    // Test normal
    double n = rng.normal(0, 1);
    assert(std::abs(n) < 10.0); // Simple sanity check

    // Test exponential
    double e = rng.exponential(1.0);
    assert(e >= 0.0);

    // Test poisson
    int p = rng.poisson(5.0);
    assert(p >= 0);

    // Test binomial
    int bin = rng.binomial(10, 0.5);
    assert(bin >= 0 && bin <= 10);

    std::cout << "All tests passed!" << std::endl;
    return 0;
} 