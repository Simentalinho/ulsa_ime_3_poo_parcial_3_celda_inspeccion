#include "limitadordepeso.h"

namespace calidad {

limitadordepeso::limitadordepeso(
    const std::string& id
)
: Dispositivo(id) {
}

bool limitadordepeso::inspeccionar(
    const Pieza& pieza
) const {

    return pieza.temperatura() >= 0.0 &&
           pieza.temperatura() <= 14.0;
}

std::string
limitadordepeso::descripcion() const {

    return "limitadordepeso";
}

}