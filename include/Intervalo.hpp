// Intervalo.hpp
#ifndef INTERVALO_HPP
#define INTERVALO_HPP

class Intervalo {
private:
    double a;
    double b;

public:
    Intervalo(double a, double b);

    double ObtenerA() const;
    double ObtenerB() const;
    void ActualizarA(double nuevoA);
    void ActualizarB(double nuevoB);
};

#endif
