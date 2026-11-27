#include <iostream>

#include "Bascula.h"
#include "CalibradorLaser.h"
#include "CamaraVision.h"
#include "CeldaInspeccion.h"
#include "DatosTurno.h"
#include "ReporteTurno.h"
#include "SensorTemperatura.h"
#include "limitadordepeso.h"

using namespace calidad;

int main() {
    Bascula bascula("B-01");
    CalibradorLaser laser("L-01");
    CamaraVision camara("V-01");
    SensorTemperatura sensor("T-01");
    limitadordepeso limitador("M-01");

    CeldaInspeccion celda;
    celda.agregarDispositivo(&bascula);
    celda.agregarDispositivo(&laser);
    celda.agregarDispositivo(&camara);
    celda.agregarDispositivo(&sensor);
    celda.agregarDispositivo(&limitador);

    celda.iniciarTurno();

    for (const Pieza& pieza : piezasDelTurno()) {
        celda.procesar(pieza);
    }

    std::cout << '\n' << celda.reporte();
    return 0;
}