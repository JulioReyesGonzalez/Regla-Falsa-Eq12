// EcuacionExprtk.cpp
#include "EcuacionExprtk.hpp"

EcuacionExprtk::EcuacionExprtk(const std::string& expression_str) {
    // Construye el symbol_table y registra la variable 'x'
    symbol_table.add_variable("x", symbol_table_value);

    // Registra el symbol_table en la expresión
    expression.register_symbol_table(symbol_table);

    // Compila la nueva expresión
    if (!parser.compile(expression_str, expression)) {
        throw std::invalid_argument("Error al compilar la expresión");
    }
}

double EcuacionExprtk::CalcularValor(double valor) const {
    // Actualiza el valor de 'x' en el symbol_table
    symbol_table_value = valor;

    // Evalúa la expresión con el nuevo valor de 'x'
    return expression.value();
}
