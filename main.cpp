#include "Catalogo.h"
#include "Turno.h"
#include "ConsolaUI.h"
#include <iostream>

int main() {
    std::cout << "--- SISTEMA DE GESTIÓN DE TURNOS INICIADO ---" << std::endl;
    
    // 1. Inicializar los Datos Maestros:
    // Carga los productos y precios fijos que usará la tienda.
    Catalogo::inicializar(); 
    
    // 2. Crear el Modelo de Negocio:
    // Instancia el objeto principal que contendrá todos los clientes y ventas.
    Turno turnoActual;
    
    // 3. Crear la Interfaz de Usuario (La Vista):
    // Instancia la interfaz, pasándole el objeto Turno por referencia para que pueda manipularlo.
    ConsolaUI ui(turnoActual);
    
    // 4. Iniciar el Ciclo del Programa:
    // Lanza la UI, que llama a iniciarTurno() y mostrarMenu().
    ui.iniciar();
    
    std::cout << "--- PROGRAMA FINALIZADO ---" << std::endl;
    
    return 0;
}