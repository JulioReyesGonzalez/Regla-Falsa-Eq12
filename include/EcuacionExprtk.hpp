// EcuacionExprtk.hpp
#ifndef ECUACIONEXPRTK_HPP
#define ECUACIONEXPRTK_HPP

#include <exprtk.hpp>

class EcuacionExprtk {
public:
    EcuacionExprtk(const std::string& expression_str);

    double CalcularValor(double valor) const;

private:
    mutable double symbol_table_value;  // Agrega la declaración aquí
    exprtk::symbol_table<double> symbol_table;
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;
};

#endif
