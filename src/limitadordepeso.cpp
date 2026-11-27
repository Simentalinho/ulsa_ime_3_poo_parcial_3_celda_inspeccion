#include "limitadordepeso.h"

namespace calidad {

limitadordepeso::limitadordepeso(const std::string& id)
    : Dispositivo(id) {
}

bool limitadordepeso::inspeccionar(const Pieza& pieza) const {
    return pieza.peso() <= 14.0;
}

std::string limitadordepeso::descripcion() const {
    return "Limitador de peso";
}

}