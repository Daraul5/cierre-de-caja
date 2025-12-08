#ifndef CONSOLAUI_H
#define CONSOLAUI_H


#include "turno.h"
class ConsolaUI {
private:
    Turno& turno_;

    void mostrarMenu();
    void gestionarCliente();
    void mostrarTotales();
    void iniciarTurno();

    void mostrarmenugestionarcliente(Cliente* cliente);
    void registrarNuevaCompra(Cliente* cliente);
    void modificarProductoExistente(Cliente* cliente);
public:
    ConsolaUI(Turno& turno);
    void iniciar();


};
#endif // CONSOLAUI_H