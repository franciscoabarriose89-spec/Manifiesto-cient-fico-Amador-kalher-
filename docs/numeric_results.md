# Technical Appendix and Numeric Results

This appendix complements the scientific article in `docs/academic_dossier.tex` with a reproducible set of numerical checks and a technical derivation section.

## Formal definitions

For a positive vector $x = (x_1, \ldots, x_n)$:

- total magnitude: $T(x) = \sum_{i=1}^{n} x_i$
- quadratic energy: $E(x) = \sum_{i=1}^{n} x_i^2$
- arithmetic decomposition index: $\mathcal{D}(x) = \frac{E(x)}{T(x)+1}$
- coherence index: $\mathcal{K}(x) = 1 - \exp\left(-\frac{\mathcal{D}(x)}{\max\{1,n\}}\right)$

## Representative numerical results

| Scenario | $\mathcal{D}(x)$ | $\mathcal{K}(x)$ |
|---|---:|---:|
| $x=(1,2,3,4)$ | 2.7272727273 | 0.4946 |
| Uniform $c=0.5$, $n=10$ | 0.4166666667 | 0.0409 |
| Uniform $c=1.0$, $n=10$ | 0.9090909091 | 0.0868 |
| Uniform $c=2.0$, $n=10$ | 1.9047619048 | 0.1724 |
| Uniform $c=5.0$, $n=10$ | 4.9019607843 | 0.3876 |

## Interpretation

- The decomposition index grows with the concentration and magnitude of the vector.
- The coherence index remains bounded in the interval $[0, 1)$.
- The uniform case confirms both monotonic growth and robust regularity.

## Reproducibility

The same calculations are reproduced in:

- `code/python/ak_proof_demo.py`
- `code/cpp/ak_proof_demo.cpp`
