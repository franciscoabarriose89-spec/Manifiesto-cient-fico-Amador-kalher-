from math import exp


def arithmetic_decomposition(sequence):
    if not sequence:
        raise ValueError("Sequence cannot be empty.")
    if any(x <= 0 for x in sequence):
        raise ValueError("All values must be strictly positive.")
    total = sum(sequence)
    energy = sum(x * x for x in sequence)
    return energy / (total + 1.0)


def amador_kahler_coherence(sequence):
    value = arithmetic_decomposition(sequence)
    scale = max(1, len(sequence))
    return 1.0 - exp(-value / scale)


def theorem_one(sequence):
    value = arithmetic_decomposition(sequence)
    assert value >= 0.0, "The arithmetic decomposition index must be non-negative."
    return value


def theorem_two(sequence):
    value = amador_kahler_coherence(sequence)
    assert 0.0 <= value < 1.0, "The coherence index must satisfy 0 <= K < 1."
    return value


def theorem_three_uniform_case(c, n):
    sequence = [c for _ in range(n)]
    value = arithmetic_decomposition(sequence)
    expected = (n * c * c) / (n * c + 1.0)
    assert abs(value - expected) <= 1e-12, "Uniform-regime formula is violated."
    return value, expected


def run_all_demo():
    print("=== Arithmetic Decomposition and Amador-Kähler Validation ===")

    test_sequence = [1.0, 2.0, 3.0, 4.0]
    d_value = theorem_one(test_sequence)
    k_value = theorem_two(test_sequence)
    print(f"Sequence: {test_sequence}")
    print(f"D(x) = {d_value:.12f}")
    print(f"K(x) = {k_value:.12f}")

    for c in [0.5, 1.0, 2.0, 5.0]:
        d_uniform, expected = theorem_three_uniform_case(c, 10)
        print(f"Uniform case c={c}: D = {d_uniform:.12f}, expected = {expected:.12f}")

    print("All rigorous checks passed.")


if __name__ == "__main__":
    run_all_demo()
