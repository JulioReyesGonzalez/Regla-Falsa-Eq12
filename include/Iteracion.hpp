// Iteracion.hpp
#ifndef ITERACION_HPP
#define ITERACION_HPP

class Iteracion {
private:
    int numero;
    double anteriorXr;
    double toleranciaDeseada;

public:
    Iteracion();

    int ObtenerNumero() const;
    double ObtenerAnteriorXr() const;
    double ObtenerToleranciaDeseada() const;

    void IncrementarNumero();
    void ActualizarAnteriorXr(double nuevoXr);
};

#endif
