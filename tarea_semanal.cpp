#include "tarea_semanal.h"

TareaSemanal::TareaSemanal(const std::string &titulo, const std::string &descripcion, const std::string &fecha)
    : TareaBase(titulo, descripcion, fecha)
{
}

std::string TareaSemanal::getTipo() const
{
    return "Tarea Semanal";
}
