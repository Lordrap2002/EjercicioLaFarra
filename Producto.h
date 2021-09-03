#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <stdlib.h>
#include "TipoProducto.h"

using std::cin;
using std::cout;
using std::string;

class Producto{
    private:
        string nombre;
        float precio, costo;
        int cantUnidades, codigo;
        TipoProducto tipoProducto;
    public:
        Producto();
        Producto(TipoProducto tipoProducto, string nombre, float precio, float costo, int codigo, int cantUnidades);
        void mostrarProducto();
        string getNombre();
        void setNombre(string nombre);
        float getPrecio();
        void setPrecio(float precio);
        int getCodigo();
        void setCodigo(int codigo);
        float getCosto();
        void setCosto(float costo);
        int getCantUnidades();
        void setCantUnidades(int cantUnidades);
        TipoProducto getTipoProducto();
        void setTipoProducto(TipoProducto tipoProducto);
};

#endif