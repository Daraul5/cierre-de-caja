#include "turno.h"  
#include "consolaui.h"

int main() {
    Turno turno;
    ConsolaUI ui(turno);
    ui.iniciar();
    return 0;
}