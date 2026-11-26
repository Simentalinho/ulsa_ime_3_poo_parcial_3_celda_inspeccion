#pragma once

#include <string>

#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

class Bascula final
    : public Dispositivo,
      public Calibrable {

private:
    double desfase_;

public:
    explicit Bascula(const std::string& id);

    bool inspeccionar(const Pieza& pieza) const override;

    std::string descripcion() const override;

    bool calibrar() override;
};

}