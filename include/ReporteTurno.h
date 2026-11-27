#pragma once

#include <map>
#include <ostream>
#include <string>

namespace calidad {

/**
 * @brief Almacena los resultados de inspección de un turno.
 *
 * Registra piezas inspeccionadas, aceptadas y rechazadas,
 * así como la cantidad de rechazos por dispositivo.
 */
class ReporteTurno {

private:
    int inspeccionadas_;
    int aceptadas_;

    // Identificador del dispositivo y cantidad de rechazos.
    std::map<std::string, int> rechazos_;

public:

    // Constructor para inicializar un reporte vacío.
    ReporteTurno();

    // Constructor para inicializar un reporte con datos existentes.
    ReporteTurno(int inspeccionadas, int aceptadas,
                 const std::map<std::string, int>& rechazos);

    // Registra el resultado de la inspección de una pieza.
    void registrarPieza(bool aceptada);

    // Registra un rechazo asociado a un dispositivo.
    void registrarRechazo(const std::string& idDispositivo);

    // Consultas de resultados del turno.
    [[nodiscard]] int inspeccionadas() const;
    [[nodiscard]] int aceptadas() const;
    [[nodiscard]] int rechazadas() const;

    // Compara dos reportes de inspección.
    [[nodiscard]] bool operator==(const ReporteTurno& otro) const;

    // Permite mostrar el reporte mediante un flujo de salida.
    friend std::ostream& operator<<(std::ostream& os,
                                    const ReporteTurno& r);
};

}