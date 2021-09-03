#ifndef TIPOPRODUCTO_H
#define TIPOPRODUCTO_H

#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::string;

class TipoProducto{
    private:
        string nombre;
        float iva;
    public:
        TipoProducto();
        TipoProducto(string nombre, float iva);
        string getNombre();
        void setNombre(string nombre);
        float getIva();
        void setIva(float iva);
};

#endif