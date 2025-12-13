#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include <string>
#include "produto.h"

class Catalogo {
private:
    std::vector<Produto> productosDisponibles_;
    static void cargarCatalogo();

public:
    static void inicializarCatalogo();
    static Producto obtenerProductoPorNombre(const string& nombre);
    static const std::vector<Produto>& getproductosdisponibles();
};

#endif // CATALOGO_H
