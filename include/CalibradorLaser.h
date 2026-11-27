#pragma once

#include <string>

#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

/**
 * @brief Dispositivo encargado de medir la longitud de las piezas.
 * Permite realizar inspecciones y calibrar el desfase de medición.
 */
class CalibradorLaser final
    : public Dispositivo,
      public Calibrable {

private:
    double desfase_; // Corrección aplicada a la medición en milímetros.

public:
    explicit CalibradorLaser(const std::string& id);

    // Verifica que la longitud medida esté dentro del rango permitido.
    bool inspeccionar(const Pieza& pieza) const override;

    // Devuelve el nombre del dispositivo.
    std::string descripcion() const override;

    // Ajusta el desfase del dispositivo a cero.
    bool calibrar() override;
};

}
