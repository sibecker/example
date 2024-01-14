#include "example.h"
#include <complex>

int f(int n) {
    static const std::complex<double> i(0.0, 1.0);
    static const auto half_pi = std::acos(0.0);
    static const auto alpha = std::asinh(0.5); // Accurate to 2 ulps
    static const auto beta = alpha - i * half_pi;
    static const auto denominator = std::cosh(alpha);  // Cumulatively accurate to 3 ulps

    auto const numerator = std::pow(i, n) * std::sinh(double(n) * beta);  // Cumulatively accurate to 5 ulps, and perfect when n == 0
    // Result is mathematically an integer.  We are at most 9 ulps out, so rounding gives the correct result, if it is respresentable by a 32-bit int
    auto const result = numerator / denominator; // Cumulative accurate to 9 ups
    return static_cast<int>(std::round(result.real()));
}
