#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include <string>
#include "Producto.h"

class Catalogo {
private:
    static std::vector<Producto> productosDisponibles_;
    static void cargarCatalogo();

public:
    static void inicializar();
    static Producto obtenerProductoPorNombre(const std::string& nombre);
    static const std::vector<Producto>& getproductosdisponibles();
};

#endif // CATALOGO_H
