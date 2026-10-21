# Manifesto Científico Amador-Kähler

Este repositorio contiene una versión académica formal del marco conceptual asociado a la deconstrucción aritmética y al índice de coherencia Amador-Kähler. La estructura actual incluye una versión de artículo científico, demostraciones rigurosas, y validación computacional reproducible.

## Componentes del dossier

- `docs/academic_dossier.tex` : manuscrito científico formal con abstract, metodología, proposiciones, teoremas y bibliografía.
- `docs/academic_dossier.bib` : referencias bibliográficas mínimas.
- `code/python/ak_proof_demo.py` : validación formal en Python puro.
- `code/cpp/ak_proof_demo.cpp` : validación formal en C++.

## Artículo científico

La versión actual del dossier tiene un formato orientado a la academia internacional:

- abstract y palabras clave;
- introducción; 
- fundamentos formales;
- principios metodológicos;
- resultados principales con pruebas;
- interpretación científica;
- validación computacional;
- conclusiones.

## Ejecución

### Python

```bash
python3 code/python/ak_proof_demo.py
```

### C++

```bash
g++ -std=c++17 code/cpp/ak_proof_demo.cpp -o ak_demo && ./ak_demo
```

## Estado

La versión actual está preparada para una revisión académica formal y puede extenderse con nuevas secciones, datos experimentales o anexos especializados.
