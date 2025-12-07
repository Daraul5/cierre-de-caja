#include "producto.h"

Producto::Producto(const std::string &nombre, float precio, int cantidad){
    this->nombre = nombre;
    this->precio_ = precio;
    this->cantidad_ = cantidad;
}

const std::string& Producto::getNombre() const {
    return nombre;
}
float Producto::getPrecio() const {
    return precio_;
}
int Producto::getCantidad() const {
    return cantidad_;
}
float Producto::getSubTotal() const {
    return precio_ * cantidad_;
}

void Producto::setCantidad(int cantidad) {
    cantidad_ = cantidad;
}
void Producto::setPrecio(float precio) {
    precio_ = precio;
}
void Producto::setNombre(const std::string &nombre) {
    this->nombre = nombre;
}