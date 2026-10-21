# Manifesto Científico Amador-Kähler

Este repositorio reúne una versión formal y demostrativa del marco conceptual asociado a la deconstrucción aritmética y al Marco Amador-Kähler. El objetivo es ofrecer una base académica utilizable para revisión, validación y divulgación en entornos de investigación de nivel internacional.

## Estructura

- `docs/academic_dossier.tex` : manuscrito académico en LaTeX, con formulación, definiciones, teoremas y demostraciones.
- `docs/academic_dossier.bib` : bibliografía mínima compatible con formatos científicos globales.
- `code/python/ak_proof_demo.py` : demostraciones rigurosas en Python puro.
- `code/cpp/ak_proof_demo.cpp` : versión equivalente en C++.

## Objetivo científico

El proyecto formaliza una métrica de descomposición aritmética y un índice de coherencia Amador-Kähler para secuencias positivas de datos. Las demostraciones incluidas verifican propiedades fundamentales como:

- no negatividad;
- acotación del índice de coherencia;
- estabilidad en el caso uniforme;
- comportamiento cuantitativo en régimen constante.

## Cómo ejecutar las pruebas

### Python

```bash
python3 code/python/ak_proof_demo.py
```

### C++

```bash
g++ -std=c++17 code/cpp/ak_proof_demo.cpp -o ak_demo
./ak_demo
```

## Nota metodológica

Las formulaciones presentadas tienen carácter de prototipo formal para revisión académica. Se integran como demostraciones de consistencia y validación simbólica dentro del marco conceptual del repositorio.
