#ifndef TAREA_DIARIA_H
#define TAREA_DIARIA_H

#include "tareabase.h"

class TareaDiaria : public TareaBase
{
public:
    TareaDiaria(const std::string &titulo, const std::string &descripcion, const std::string &fecha);
    std::string getTipo() const override;
};

#endif // TAREA_DIARIA_H
