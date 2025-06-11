# stats_lib


## 🚀 What is this?
A modern C++17 header+static library for probability distributions, random number generation, and statistical estimation. Minimal dependencies, maximum speed. Use it for quant, ML, or whenever you need some stats in C++.

## 📦 Features
- Probability distributions (Normal, Beta, Gamma, Poisson, Binomial, etc.)
- Random number generators
- Estimation routines (MLE, etc.)
- Clean API, header-first, easy to extend
- No STL bloat, no boost, just stats

## 🛠️ Build & Install
```sh
# Classic CMake build
mkdir build && cd build
cmake ..
make

# Install (optional, for system-wide use)
sudo make install
```

## 🧑‍💻 Quickstart
```cpp
#include <stats_lib/stats_lib/distribution.hpp>
#include <iostream>

int main() {
    double mu = 0.0, sigma = 1.0;
    double x = 1.5;
    std::cout << "Normal PDF at x=" << x << ": "
              << stats::distributions::normal_pdf(x, mu, sigma) << std::endl;
    return 0;
}
```

Compile it:
```sh
g++ -std=c++17 -I/path/to/stats_lib/include your_file.cpp -L/path/to/stats_lib/build -lstats_lib -o demo
```

## 🏗️ CMake Integration
```cmake
find_package(stats_lib REQUIRED)
target_link_libraries(your_target PRIVATE stats_lib::stats_lib)
```

## 🤘 Contributing
PRs welcome. If you break the build, you owe everyone coffee.

## 📝 License
MIT. Use it, abuse it, just don't sue us.

---

*Built by devs who think statistics should be fast, fun, and frustration-free.*
