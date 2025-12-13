#include "catalogo.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

std::vector<Producto> Catalogo::productosDisponibles_;
std::string tolower(const std::string& str){
    std::string lower_Str = str;
    std::transform(lower_Str.begin(), lower_Str.end(), lower_Str.begin(), 
                    [](unsigned char c){ return std::tolower(c);});
    return lower_Str;
}

void Catalogo::cargarCatalogo(){
    // Definimos los productos y servicios FIJOS de la tienda
    productosDisponibles_.emplace_back("Recarga Telcel $100", 100.0f, 1);
    productosDisponibles_.emplace_back("Sabritas", 15.0f, 1);
    productosDisponibles_.emplace_back("Coca Cola 600ml", 18.0f, 1);
    
    // Servicios (Precio unitario puede ser 1 o 0, ya que el cálculo se hace diferente)
    productosDisponibles_.emplace_back("Copia B/N", 1.0f, 1); 
    productosDisponibles_.emplace_back("Impresion Color", 5.0f, 1);
    
    // Cibercafé (Precio por hora o tiempo)
    productosDisponibles_.emplace_back("Internet 1 Hora", 12.0f, 1);
    productosDisponibles_.emplace_back("Internet 30 Minutos", 7.0f, 1);

    std::cout << "Catalogo cargado con " << productosDisponibles_.size() << " productos y servicios." << std::endl;
}

void Catalogo::inicializar(){
    if(Catalogo::productosDisponibles_.empty()){
        cargarCatalogo();
    }
}

Producto Catalogo::obtenerProductoPorNombre(const std::string& nombre){
    std::string nombreBuscado = tolower(nombre);

    for(const auto& producto : productosDisponibles_){
        if(tolower(producto.getNombre())== nombreBuscado){
            return producto;
        }
    }
    return Producto{"producto no encontrado", 0.0f, 0}; // Producto no encontrado
}

const std::vector<Producto>& Catalogo::getproductosdisponibles(){
    return productosDisponibles_;
}