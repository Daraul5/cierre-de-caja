#ifndef TIPOPRODUCTO_H
#define TIPOPRODUCTO_H

#include <string>
#include <vector>
#include "producto.h"

class Tipoproducto
{
private:
    std::string nombreTipo_;
    std::vector<Producto> productos_;

public:
    Tipoproducto(const std::string& nombreTipo);

    const std::string& getNombreTipo() const;
    const std::vector<Producto>& getProductos() const;
    float getSumaTipos() const;

    void agregarProducto(const Producto& producto);
    Producto* buscarProducto(size_t index);
};



#endif // TIPOPRODUCTO_H