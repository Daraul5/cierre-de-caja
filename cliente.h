#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "tipoproducto.h"
class Cliente {
private:
    std::vector<Tipoproducto> tipos_;
    int id_;
public:
    Cliente();
    Cliente(int id) : id_(id){}

    float getSumaTotal() const;
    float getSumaProductos() const;
    float getSumaServicios() const;
    float getSumaCibercafe() const;

    const std::vector<Tipoproducto>& getTipos() const;
    Tipoproducto* buscarTipoInterno(const std::string& nombreTipo);
    void registrarCompra(const std::string& nombreTipo, const Producto& p);
    void inicializarTipos();
    int getId() const { return id_; }

};

#endif // CLIENTE_H