#ifndef TAREABASE_H
#define TAREABASE_H

#include <string>

class TareaBase
{
public:
    TareaBase(const std::string &titulo, const std::string &descripcion, const std::string &fecha);
    virtual ~TareaBase() = default;

    virtual std::string getTipo() const = 0;
    std::string getTitulo() const { return titulo; }
    std::string getDescripcion() const { return descripcion; }
    std::string getFecha() const { return fecha; }

protected:
    std::string titulo;
    std::string descripcion;
    std::string fecha;
};

#endif // TAREABASE_H
