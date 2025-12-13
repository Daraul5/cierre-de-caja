#include "consolaui.h"
#include "Catalogo.h"
#include <iostream>

ConsolaUI::ConsolaUI(Turno& turno) : turno_(turno) {}


void ConsolaUI::iniciar() {
    iniciarTurno();
    mostrarMenu();
}
void ConsolaUI::iniciarTurno() {
    std::string encargado;
    std::cout << "Ingrese el nombre del encargado del turno: ";
    std::getline(std::cin, encargado);
    turno_.setEncargado(encargado);
}

void ConsolaUI::mostrarMenu() {
    int opcion;
    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Gestionar Cliente\n";
        std::cout << "2. Mostrar Totales\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1:
                gestionarCliente();
                break;
            case 2:
                mostrarTotales();
                break;
            case 3:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}

void ConsolaUI::gestionarCliente() {
    int idCliente;
    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> idCliente;
    std::cin.ignore(); // Limpiar el buffer
    Cliente* cliente = turno_.buscarCliente(idCliente);
    if (cliente) {
        mostrarmenugestionarcliente(cliente);
    } else {
        std::cout << "Cliente no encontrado. Desea registrarlo? (s/n): ";
        char respuesta;
        std::cin >> respuesta;
        std::cin.ignore(); // Limpiar el buffer
        if (respuesta == 's' || respuesta == 'S') {
            Cliente nuevoCliente(idCliente);
            turno_.agregarCliente(nuevoCliente);
            std::cout << "Cliente registrado exitosamente.\n";
        }
    }
}

void ConsolaUI::mostrarTotales() {
    std::cout << "\n--- Totales del Turno ---\n";
    std::cout << "Encargado: " << turno_.getEncargado() << "\n";
    std::cout << "Total Productos/Recargas: " << turno_.getTotalProductosRecargas() << "\n";
    std::cout << "Total Servicios: " << turno_.getTotalServicios() << "\n";
    std::cout << "Total Cibercafe: " << turno_.getTotalCibercafe() << "\n";
    std::cout << "Gran Total: " << turno_.getGrandeTotal() << "\n";
}
void ConsolaUI::mostrarmenugestionarcliente(Cliente* cliente) {
    int opcion;
    do {
        std::cout << "\n--- Gestionar Cliente ID: " << cliente->getId() << " ---\n";
        std::cout << "1. Registrar Nueva Compra\n";
        std::cout << "2. Modificar Producto Existente\n";
        std::cout << "3. Volver al Menu Principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1:
                registrarNuevaCompra(cliente);
                break;
            case 2:
                modificarProductoExistente(cliente);
                break;
            case 3:
                std::cout << "Volviendo al menu principal...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}
// ConsolaUI.cpp

void ConsolaUI::registrarNuevaCompra(Cliente* cliente) {
    if (!cliente) return;

    std::string nombreTipo;
    std::string nombreProducto;
    int cantidad = 0;

    std::cout << "\n--- REGISTRAR COMPRA (Cliente ID: " << cliente->getId() << ") ---" << std::endl;
    std::cout << "Categorías: [productos y recargas], [servicios], [cibercafe]" << std::endl;
    std::cout << "Ingrese la CATEGORÍA de la compra: ";
    std::getline(std::cin >> std::ws, nombreTipo);
    
    // Aquí podrías mostrar el catálogo para ayudar al usuario
    std::cout << "Ingrese el NOMBRE del producto (ej: Sabritas): ";
    std::getline(std::cin, nombreProducto);
    
    // Obtener el producto base del catálogo
    Producto productoBase = Catalogo::obtenerProductoPorNombre(nombreProducto); 

    if (productoBase.getPrecio() > 0.0f) { // <-- ¡CORREGIDO: Usando getPrecio() en la condición!
        std::cout << "Precio unitario: $" << productoBase.getPrecio() << std::endl; // <-- ¡CORREGIDO: Usando getPrecio() en la salida!
        
        std::cout << "Ingrese la CANTIDAD a comprar: ";
        if (!(std::cin >> cantidad) || cantidad <= 0) {
            std::cout << "Error: Cantidad no válida." << std::endl;
            std::cin.clear(); std::cin.ignore(10000, '\n');
            return;
        }
        std::cin.ignore();

        // Modificar la cantidad del objeto Producto y registrar
        productoBase.setCantidad(cantidad);
        cliente->registrarCompra(nombreTipo, productoBase);
        
        std::cout << "\n Compra registrada. Nuevo Total Cliente: $" << cliente->getSumaTotal() << std::endl;
    } else {
        std::cout << " Producto '" << nombreProducto << "' no encontrado en el catálogo." << std::endl;
    }
}
void ConsolaUI::modificarProductoExistente(Cliente* cliente){
    if (!cliente) return;
    std::string nombreTipo;
    int indiceProducto;
    int nuevaCantidad;
    std::cout << "\n--- MODIFICAR PRODUCTO EXISTENTE (Cliente ID: " << cliente->getId() << ") ---" << std::endl;
    std::cout << "Total actual del cliente: $" << cliente->getSumaTotal() << std::endl;
    std::cout << "Categorías: [productos y recargas], [servicios], [cibercafe]" << std::endl;

    std::cout << "Ingrese la categoría del producto a modificar: ";
    std::getline(std::cin >> std::ws, nombreTipo);

    Tipoproducto* tipo = cliente->buscarTipoInterno(nombreTipo);

    if (!tipo) {
        std::cout << "Categoría no encontrada para este cliente." << std::endl;
        return;
    }
    std::cout << "\nProductos en la categoría '" << tipo->getNombreTipo() << "':" << std::endl;
    int i = 1;

    for (const auto& producto : tipo->getProductos()) {
        std::cout << i++ << ". " << producto.getNombre() 
        << " - Cantidad: " << producto.getCantidad() 
        << " - Subtotal: $" << producto.getSubTotal()
        << std::endl;
    }
    if (tipo->getProductos().empty()) {
        std::cout << "No hay productos en esta categoría para modificar." << std::endl;
        return;
    }
    std::cout << "2. Ingrese el número (índice) del producto a modificar: ";
    if (!(std::cin >> indiceProducto)) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Entrada inválida." << std::endl;
        return;
    }
    std::cin.ignore(); // Limpiar el buffer

    // Buscar el Producto (el índice del usuario es 1-basado, el vector es 0-basado)
    Producto* producto = tipo->buscarProducto(indiceProducto - 1);

    if (!producto) {
        std::cout << "Error: Índice de producto fuera de rango." << std::endl;
        return;
    }

    // --- PASO 3: Modificar la Cantidad (La magia POO) ---
    std::cout << "\nProducto seleccionado: " << producto->getNombre() 
            << " (Cantidad actual: " << producto->getCantidad() << ")" << std::endl;
    std::cout << "3. Ingrese la NUEVA cantidad: ";
    if (!(std::cin >> nuevaCantidad)) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Entrada inválida." << std::endl;
        return;
    }
    std::cin.ignore(); // Limpiar el buffer

    // Aplicar el cambio. ¡Todo el recálculo ocurre automáticamente!
    producto->setCantidad(nuevaCantidad); 

    std::cout << "\n========================================" << std::endl;
    std::cout << " Producto modificado exitosamente." << std::endl;
    std::cout << "Nuevo Subtotal del cliente: $" << cliente->getSumaTotal() << std::endl;
    std::cout << "========================================" << std::endl;
}