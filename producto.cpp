#include "producto.h"

Producto::Producto(const std::string& nombre, float precio, int cantidad)
    : nombre(nombre), precio_(precio), cantidad_(cantidad) {}

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
void Producto::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}
void Producto::setPrecio(float nuevoPrecio) {
    precio_ = nuevoPrecio;
}
void Producto::setCantidad(int nuevaCantidad) {
    cantidad_ = nuevaCantidad;
}
