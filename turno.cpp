#include "turno.h"
#include <algorithm>


Turno::Turno() : encargado_("") {}

const std::string& Turno::getEncargado() const {
    return encargado_;
}
const std::vector<Cliente>& Turno::getClientes() const {
    return clientes_;
}
float Turno::getGrandeTotal() const {
    float total = 0.0f;
    for (const auto& cliente : clientes_) {
        total += cliente.getSumaTotal();
    }
    return total;
}
float Turno::getTotalProductosRecargas() const {
    float total = 0.0f;
    for (const auto& cliente : clientes_) {
        total += cliente.getSumaProductos();
    }
    return total;
}
float Turno::getTotalServicios() const {
    float total = 0.0f;
    for (const auto& cliente : clientes_) {
        total += cliente.getSumaServicios();
    }
    return total;
}
float Turno::getTotalCibercafe() const {
    float total = 0.0f;
    for (const auto& cliente : clientes_) {
        total += cliente.getSumaCibercafe();
    }
    return total;
}
void Turno::setEncargado(const std::string& encargado) {
    encargado_ = encargado;
}
void Turno::agregarCliente(const Cliente& c) {
    clientes_.push_back(c);
}
Cliente* Turno::buscarCliente(int idCliente) {
    if(idCliente <=0){
        return nullptr;
    }

    size_t indice = idCliente - 1;

    if (indice < clientes_.size()) {
        return &clientes_[indice];
    } else {
        return nullptr;
    }
    return nullptr;
}

void Turno::ordenarClienteascendente() {
    std::sort(clientes_.begin(), clientes_.end(), [](const Cliente& a, const Cliente& b) {
        return a.getSumaTotal() < b.getSumaTotal();
    });
}
void Turno::ordenarClientedesendente() {
    std::sort(clientes_.begin(), clientes_.end(), [](const Cliente& a, const Cliente& b) {
        return a.getSumaTotal() > b.getSumaTotal();
    });
}