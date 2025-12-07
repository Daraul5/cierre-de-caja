#include "tipoproducto.h"

Tipoproducto::Tipoproducto(const std::string& nombreTipo)
    : nombreTipo_(nombreTipo) {}

const std::string& Tipoproducto::getNombreTipo() const {
    return nombreTipo_;
}
const std::vector<Producto>& Tipoproducto::getProductos() const {
    return productos_;
}
float Tipoproducto::getSumaTipos() const 
{
    float suma = 0;
    for (const auto& producto : productos_){
        suma += producto.getSubTotal();
    }
    return suma;
}

void Tipoproducto::agregarProducto(const Producto &producto)
{
    productos_.push_back(producto);
}
Producto* Tipoproducto::buscarProducto(size_t index)
{
    if (index < productos_.size()) {
        return &productos_[index];
    }
    return nullptr;
}
