#include <iostream>

#include "Bascula.h"
#include "CalibradorLaser.h"
#include "CamaraVision.h"
#include "SensorTemperatura.h"

#include "CeldaInspeccion.h"
#include "DatosTurno.h"
#include "ReporteTurno.h"

using namespace calidad;

int main() {

    // Crear dispositivos
    Bascula bascula("B-01");
    CalibradorLaser laser("L-01");
    CamaraVision camara("V-01");
    SensorTemperatura sensor("T-01");

    // Crear celda de inspección
    CeldaInspeccion celda;

    // Agregar dispositivos
    celda.agregarDispositivo(&bascula);
    celda.agregarDispositivo(&laser);
    celda.agregarDispositivo(&camara);
    celda.agregarDispositivo(&sensor);

    // Iniciar turno y calibrar dispositivos
    celda.iniciarTurno();

    // Procesar todas las piezas
    for (const Pieza& pieza : piezasDelTurno()) {
        celda.procesar(pieza);
    }

    // Mostrar reporte
    std::cout << "\n";
    std::cout << celda.reporte();

    // Crear reporte esperado
    ReporteTurno esperado(
        12,
        6,
        {
            {"B-01", 2},
            {"L-01", 2},
            {"T-01", 2},
            {"V-01", 2}
        }
    );

    // Comparar resultados
    if (celda.reporte() == esperado) {
        std::cout << "\nReporte correcto\n";
    } else {
        std::cout << "\nReporte con diferencias\n";
    }

    return 0;
}