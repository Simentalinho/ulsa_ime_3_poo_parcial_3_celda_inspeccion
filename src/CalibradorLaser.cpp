#include "CalibradorLaser.h"

namespace calidad {

// Constructor: establece el desfase inicial del sensor.
CalibradorLaser::CalibradorLaser(const std::string& id)
    : Dispositivo(id),
      desfase_(-0.3) {
}

// Comprueba si la longitud de la pieza está dentro del rango permitido.
bool CalibradorLaser::inspeccionar(const Pieza& pieza) const {

    const double largoMedido = pieza.largo() + desfase_;

    constexpr double LONGITUD_MINIMA = 49.5;
    constexpr double LONGITUD_MAXIMA = 50.5;

    return largoMedido >= LONGITUD_MINIMA &&
           largoMedido <= LONGITUD_MAXIMA;
}

// Devuelve la identificación descriptiva del dispositivo.
std::string CalibradorLaser::descripcion() const {
    return "Calibrador laser";
}

// Elimina el desfase para restablecer la medición.
bool CalibradorLaser::calibrar() {
    desfase_ = 0.0;
    return true;
}

}