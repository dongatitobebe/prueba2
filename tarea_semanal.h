#ifndef TAREA_SEMANAL_H
#define TAREA_SEMANAL_H

#include "tareabase.h"

class TareaSemanal : public TareaBase
{
public:
    TareaSemanal(const std::string &titulo, const std::string &descripcion, const std::string &fecha);
    std::string getTipo() const override;
};

#endif // TAREA_SEMANAL_H
