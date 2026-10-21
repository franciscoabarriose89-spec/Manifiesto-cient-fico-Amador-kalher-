#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

double arithmetic_decomposition(const std::vector<double>& sequence) {
    if (sequence.empty()) {
        throw std::invalid_argument("Sequence cannot be empty.");
    }
    for (double x : sequence) {
        if (x <= 0.0) {
            throw std::invalid_argument("All values must be strictly positive.");
        }
    }

    double total = 0.0;
    double energy = 0.0;
    for (double x : sequence) {
        total += x;
        energy += x * x;
    }
    return energy / (total + 1.0);
}

double amador_kahler_coherence(const std::vector<double>& sequence) {
    double value = arithmetic_decomposition(sequence);
    size_t scale = std::max<size_t>(1, sequence.size());
    return 1.0 - std::exp(-value / static_cast<double>(scale));
}

void theorem_one(const std::vector<double>& sequence) {
    double value = arithmetic_decomposition(sequence);
    if (!(value >= 0.0)) {
        throw std::logic_error("The arithmetic decomposition index must be non-negative.");
    }
    std::cout << "Theorem 1: D(x) = " << value << " >= 0\n";
}

void theorem_two(const std::vector<double>& sequence) {
    double value = amador_kahler_coherence(sequence);
    if (!(0.0 <= value && value < 1.0)) {
        throw std::logic_error("The coherence index must satisfy 0 <= K < 1.");
    }
    std::cout << "Theorem 2: K(x) = " << value << " belongs to [0,1)\n";
}

void theorem_three_uniform_case(double c, int n) {
    std::vector<double> sequence(n, c);
    double value = arithmetic_decomposition(sequence);
    double expected = (n * c * c) / (n * c + 1.0);

    if (std::abs(value - expected) > 1e-12) {
        throw std::logic_error("Uniform-regime formula is violated.");
    }

    std::cout << "Theorem 3: uniform case c=" << c << ", D = " << value
              << ", expected = " << expected << "\n";
}

int main() {
    std::cout << "=== Arithmetic Decomposition and Amador-Kähler Validation (C++) ===\n";

    std::vector<double> test_sequence = {1.0, 2.0, 3.0, 4.0};
    theorem_one(test_sequence);
    theorem_two(test_sequence);

    theorem_three_uniform_case(0.5, 10);
    theorem_three_uniform_case(1.0, 10);
    theorem_three_uniform_case(2.0, 10);
    theorem_three_uniform_case(5.0, 10);

    std::cout << "All rigorous checks passed.\n";
    return 0;
}
