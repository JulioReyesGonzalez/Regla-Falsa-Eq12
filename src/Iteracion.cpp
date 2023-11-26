// Iteracion.cpp
#include "Iteracion.hpp"

Iteracion::Iteracion() : numero(1), anteriorXr(0), toleranciaDeseada(0.001) {}

int Iteracion::ObtenerNumero() const {
    return numero;
}

double Iteracion::ObtenerAnteriorXr() const {
    return anteriorXr;
}

double Iteracion::ObtenerToleranciaDeseada() const {
    return toleranciaDeseada;
}

void Iteracion::IncrementarNumero() {
    numero++;
}

void Iteracion::ActualizarAnteriorXr(double nuevoXr) {
    anteriorXr = nuevoXr;
}
