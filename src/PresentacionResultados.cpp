// PresentacionResultados.cpp
#include "PresentacionResultados.hpp"
#include <iostream>

void PresentacionResultados::ImprimirEncabezado() {
    std::cout << "Metodo de la Regla Falsa\n";
    std::cout << "f(x) = sin(x)-0.5 \n";
    // ... (otros encabezados si es necesario)
}

void PresentacionResultados::ImprimirIteracion(int numero, double a, double b, double fa, double fb, double xr, double fxr, double fa_fxr, double tolerancia) {
    std::cout << "| " << numero << " | " << a << " | " << b << " | " << fa << " | " << fb << " | " << xr << " | " << fxr << " | " << fa_fxr << " | " << tolerancia << " |\n";
    // ... (otros detalles de la iteración)
}

void PresentacionResultados::ImprimirLineaSeparadora() {
    std::cout << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n";
}
