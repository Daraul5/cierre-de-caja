#ifndef TURNO_H
#define TURNO_H


#include <String>
#include <vector>
#include "cliente.h"

class Turno {
private:
    std::vector<Cliente> clientes_;
    std::string encargado_;
public:
    Turno();

    const std::string& getEncargado() const;
    const std::vector<Cliente>& getClientes() const;

    float getGrandeTotal() const;
    float getTotalProductosRecargas() const;
    float getTotalServicios() const;
    float getTotalCibercafe() const;

    void setEncargado(const std::string& encargado);
    void agregarCliente(const Cliente& c);

    Cliente* buscarCliente(int idCliente);
    void ordenarClienteascendente();
    void ordenarClientedesendente();
};
#endif// TURNO_H