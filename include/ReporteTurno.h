#pragma once

#include <map>
#include <ostream>
#include <string>

namespace calidad {

class ReporteTurno {
private:
    int inspeccionadas_;
    int aceptadas_;
    std::map<std::string, int> rechazos_;

public:
    ReporteTurno();

    ReporteTurno(int inspeccionadas, int aceptadas,
                 const std::map<std::string, int>& rechazos);

    void registrarPieza(bool aceptada);
    void registrarRechazo(const std::string& idDispositivo);

    int inspeccionadas() const;
    int aceptadas() const;
    int rechazadas() const;

    bool operator==(const ReporteTurno& otro) const;

    friend std::ostream& operator<<(std::ostream& os,
                                    const ReporteTurno& r);
};

}