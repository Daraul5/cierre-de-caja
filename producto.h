#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto
{
private:
    std::string nombre;
    float precio_;
    int cantidad_;
public:
    Producto(const std::string& nombre, float precio, int cantidad);

    const std::string& getNombre() const;
    float getPrecio() const;
    int getCantidad() const;
    float getSubTotal() const;

    void setNombre(const std::string& nuevoNombre);
    void setPrecio(float nuevoPrecio);
    void setCantidad(int nuevaCantidad);
    
    
};

#endif // PRODUCTO_H