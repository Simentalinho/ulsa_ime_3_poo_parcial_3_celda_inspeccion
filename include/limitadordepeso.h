#pragma once
#include <string>
#include "Dispositivo.h"

namespace calidad {

class limitadordepeso final
    : public Dispositivo {

public:
    explicit limitadordepeso(
        const std::string& id
    );

    bool inspeccionar(
        const Pieza& pieza
    ) const override;

    std::string descripcion()
        const override;
};

} // namespace calidad
