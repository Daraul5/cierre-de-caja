#include "consolaui.h"
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
void ConsolaUI::registrarNuevaCompra(Cliente* cliente) {
    if (!cliente) return;

    std::string nombreTipo;
    std::string nombreProducto;
    int cantidad = 0;

    std::cout << "\n--- REGISTRAR COMPRA ---" << std::endl;
    std::cout << "Categorías: [productos y recargas], [servicios], [cibercafe]" << std::endl;
    std::cout << "Ingrese la categoría de la compra: ";std::cout << "\n--- REGISTRAR COMPRA ---" << std::endl;
    std::cout << "Categorías: [productos y recargas], [servicios], [cibercafe]" << std::endl;
    std::cout << "Ingrese la categoría de la compra: ";

    std::cout << "\n--- REGISTRAR COMPRA ---" << std::endl;
    std::cout << "Categorías: [productos y recargas], [servicios], [cibercafe]" << std::endl;
    std::cout << "Ingrese la categoría de la compra: ";
    std::getline(std::cin >> std::ws, nombreTipo);

}