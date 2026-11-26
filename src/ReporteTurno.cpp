#include "ReporteTurno.h"

#include <stdexcept>

namespace calidad {

// Constructor: inicializa un reporte vacío.
ReporteTurno::ReporteTurno()
    : inspeccionadas_(0),
      aceptadas_(0) {
}

// Constructor: inicializa el reporte con información existente.
ReporteTurno::ReporteTurno(
    int inspeccionadas,
    int aceptadas,
    const std::map<std::string, int>& rechazos
)
    : inspeccionadas_(inspeccionadas),
      aceptadas_(aceptadas),
      rechazos_(rechazos) {

    // Validar la consistencia de los datos recibidos.
    if (inspeccionadas < 0 ||
        aceptadas < 0 ||
        aceptadas > inspeccionadas) {
        throw std::invalid_argument(
            "Los datos del reporte no son validos."
        );
    }
}

// Registra una pieza inspeccionada.
void ReporteTurno::registrarPieza(bool aceptada) {
    ++inspeccionadas_;

    if (aceptada) {
        ++aceptadas_;
    }
}

// Registra el rechazo de un dispositivo.
void ReporteTurno::registrarRechazo(
    const std::string& idDispositivo
) {
    if (!idDispositivo.empty()) {
        ++rechazos_[idDispositivo];
    }
}

// Devuelve la cantidad de piezas inspeccionadas.
int ReporteTurno::inspeccionadas() const {
    return inspeccionadas_;
}

// Devuelve la cantidad de piezas aceptadas.
int ReporteTurno::aceptadas() const {
    return aceptadas_;
}

// Calcula la cantidad de piezas rechazadas.
int ReporteTurno::rechazadas() const {
    return inspeccionadas_ - aceptadas_;
}

// Compara los resultados de dos reportes.
bool ReporteTurno::operator==(
    const ReporteTurno& otro
) const {

    return inspeccionadas_ == otro.inspeccionadas_
        && aceptadas_ == otro.aceptadas_
        && rechazos_ == otro.rechazos_;
}

// Muestra los resultados del turno.
std::ostream& operator<<(
    std::ostream& os,
    const ReporteTurno& r
) {

    os << "=== Reporte de turno ===\n";

    os << "Inspeccionadas: "
       << r.inspeccionadas_
       << '\n';

    os << "Aceptadas: "
       << r.aceptadas_
       << '\n';

    os << "Rechazadas: "
       << r.rechazadas()
       << '\n';

    os << "Rechazos por dispositivo:\n";

    for (const auto& rechazo : r.rechazos_) {
        os << "  "
           << rechazo.first
           << ": "
           << rechazo.second
           << '\n';
    }

    return os;
}

} // namespace calidad