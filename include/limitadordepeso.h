#pragma once

#include <string>

#include "Dispositivo.h"
#include "Pieza.h"

namespace calidad {

class limitadordepeso : public Dispositivo {
public:
    explicit limitadordepeso(const std::string& id);

    bool inspeccionar(const Pieza& pieza) const override;
    std::string descripcion() const override;
};

}