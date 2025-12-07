#include "cliente.h"
Tipoproducto *Cliente::buscarTipoInterno(const std::string &nombreTipo)
{
    for(auto& tipo :tipos_)
    {
        if (tipo.getNombreTipo() == nombreTipo)
        {
            return &tipo;
        }
        
    }
    return nullptr;
}
Cliente::Cliente()
{
    inicializarTipos();
}

float Cliente::getSumaTotal() const {
    float suma = 0;
    for (const auto& tipo : tipos_) {
        suma += tipo.getSumaTipos();
    }
    return suma;
}
float Cliente::getSumaProductos() const {
    float suma = 0;
    for (const auto& tipo : tipos_) 
    {
        if (tipo.getNombreTipo() == "Producto") {
            suma += tipo.getSumaTipos();
        }
    }
    return suma;
} 
float Cliente::getSumaServicios() const {
    float suma = 0;
    for (const auto& tipo : tipos_)
    {
        if(tipo.getNombreTipo() == "Servicio")
        {
            suma += tipo.getSumaTipos();
        }
    }
    return suma;
}
float Cliente::getSumaCibercafe() const {
    float suma = 0;
    for (const auto& tipo : tipos_)
    {
        if(tipo.getNombreTipo() == "Cibercafe")
        {
            suma += tipo.getSumaTipos();
        }
    }
    return suma;
}

const std::vector<Tipoproducto>& Cliente::getTipos() const {
    return tipos_;
}


void Cliente::registrarCompra(const std::string& nombreTipo, const Producto& p) {
    Tipoproducto* tipo = buscarTipoInterno(nombreTipo);
    if (tipo != nullptr) 
    {
        tipo->agregarProducto(p);
    }
}

void Cliente::inicializarTipos() {
    tipos_.emplace_back("Producto");
    tipos_.emplace_back("Servicio");
    tipos_.emplace_back("Cibercafe");
}