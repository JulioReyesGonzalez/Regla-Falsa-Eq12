// Intervalo.cpp
#include "Intervalo.hpp"

Intervalo::Intervalo(double a, double b) : a(a), b(b) {}

double Intervalo::ObtenerA() const {
    return a;
}

double Intervalo::ObtenerB() const {
    return b;
}

void Intervalo::ActualizarA(double nuevoA) {
    a = nuevoA;
}

void Intervalo::ActualizarB(double nuevoB) {
    b = nuevoB;
}
