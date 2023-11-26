// PresentacionResultados.hpp
#ifndef PRESENTACIONRESULTADOS_HPP
#define PRESENTACIONRESULTADOS_HPP

class PresentacionResultados {
public:
    void ImprimirEncabezado();
    void ImprimirIteracion(int numero, double a, double b, double fa, double fb, double xr, double fxr, double fa_fxr, double tolerancia);
    void ImprimirLineaSeparadora();
};

#endif
