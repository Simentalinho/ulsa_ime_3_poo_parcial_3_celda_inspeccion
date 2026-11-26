#include "CeldaInspeccion.h"

#include <iostream>
#include "Calibrable.h"

namespace calidad {

void CeldaInspeccion::agregarDispositivo(Dispositivo* d) {
    if (d != nullptr) {
        dispositivos_.push_back(d);
    }
}

void CeldaInspeccion::iniciarTurno() {
    std::cout << "=== Inicio de turno ===\n";

    for (Dispositivo* d : dispositivos_) {
        if (Calibrable* c = dynamic_cast<Calibrable*>(d)) {
            std::cout << "Calibrando "
                      << d->id()
                      << " ("
                      << d->descripcion()
                      << ") ... "
                      << (c->calibrar() ? "OK" : "ERROR")
                      << '\n';
        }
    }
}

bool CeldaInspeccion::procesar(const Pieza& pieza) {
    std::cout << "\n" << pieza << '\n';

    bool aceptada = true;

    for (Dispositivo* d : dispositivos_) {
        bool resultado = d->inspeccionar(pieza);

        std::cout << "  "
                  << d->id()
                  << " ("
                  << d->descripcion()
                  << "): "
                  << (resultado ? "ACEPTA" : "RECHAZA")
                  << '\n';

        if (!resultado) {
            aceptada = false;
            reporte_.registrarRechazo(d->id());
        }
    }

    std::cout << "  -> "
              << (aceptada ? "ACEPTADA" : "RECHAZADA")
              << '\n';

    reporte_.registrarPieza(aceptada);

    return aceptada;
}

const ReporteTurno& CeldaInspeccion::reporte() const {
    return reporte_;
}

}