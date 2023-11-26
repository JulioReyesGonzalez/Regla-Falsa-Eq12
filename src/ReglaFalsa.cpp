#include "EcuacionExprtk.hpp"
#include "Intervalo.hpp"
#include "Iteracion.hpp"
#include "CalculadoraRaices.hpp"
#include "PresentacionResultados.hpp"
#include <iostream>

int main() {
    EcuacionExprtk ecuacion_exprtk("sin(x) - 0.5");
    Intervalo intervalo(1.5, 4.0);
    Iteracion iteracion;
    CalculadoraRaices calculadora;
    PresentacionResultados presentacion;

    presentacion.ImprimirEncabezado();

    double a = intervalo.ObtenerA();
    double b = intervalo.ObtenerB();
    double fa = ecuacion_exprtk.CalcularValor(a);
    double fb = ecuacion_exprtk.CalcularValor(b);

    if (fa * fb > 0) {
        std::cerr << "El intervalo no cumple con el teorema de Bolzano. No hay cambio de signo en el intervalo." << std::endl;
        return 1;
    }

    double xr, fxr, fa_fxr, tolerancia;
    int iteraciones_maximas = 100;

    do {
        xr = calculadora.ObtenerXr(a, b, fa, fb);
        fxr = ecuacion_exprtk.CalcularValor(xr);
        fa_fxr = fa * fxr;

        tolerancia = std::abs(iteracion.ObtenerAnteriorXr() - xr);

        presentacion.ImprimirIteracion(iteracion.ObtenerNumero(), a, b, fa, fb, xr, fxr, fa_fxr, tolerancia);

        if (fa_fxr > 0) {
            a = xr;
            fa = fxr;
        } else {
            b = xr;
            fb = fxr;
        }

        intervalo.ActualizarA(a);
        intervalo.ActualizarB(b);

        iteracion.ActualizarAnteriorXr(xr);
        iteracion.IncrementarNumero();

    } while (tolerancia > iteracion.ObtenerToleranciaDeseada() && iteracion.ObtenerNumero() <= iteraciones_maximas);

    presentacion.ImprimirLineaSeparadora();

    if (tolerancia <= iteracion.ObtenerToleranciaDeseada()) {
        std::cout << "La raíz aproximada es: " << xr << std::endl;
    } else {
        std::cout << "El método no convergió en " << iteraciones_maximas << " iteraciones." << std::endl;
    }

    return 0;
}
