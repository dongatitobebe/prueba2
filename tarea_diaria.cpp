#include "tarea_diaria.h"

TareaDiaria::TareaDiaria(const std::string &titulo, const std::string &descripcion, const std::string &fecha)
    : TareaBase(titulo, descripcion, fecha)
{
}

std::string TareaDiaria::getTipo() const
{
    return "Tarea Diaria";
}
