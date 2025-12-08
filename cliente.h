#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "tipoproducto.h"
class Cliente {
private:
    std::vector<Tipoproducto> tipos_;
    
public:
    Cliente();

    float getSumaTotal() const;
    float getSumaProductos() const;
    float getSumaServicios() const;
    float getSumaCibercafe() const;

    const std::vector<Tipoproducto>& getTipos() const;
    const Tipoproducto* buscarTipoInterno(const std::string& nombreTipo);
    void registrarCompra(const std::string& nombreTipo, const Producto& p);
    void inicializarTipos();
    

};

#endif // CLIENTE_H