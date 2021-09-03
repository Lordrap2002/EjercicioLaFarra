#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <stdlib.h>
#include "Producto.h"
#include "Factura.h"
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

class Tienda{
    private:
        string nombre;
        float ivaTotal, gananciaTotal;
        vector<Factura> facturas;
        map<int, Producto> inventario;
        map<int, TipoProducto> categorias;
        int contadorFacturas;
        void agregarDetalle(float &totalDelIVA, float &totalSinIVA, float &totalGeneral, Factura &factura);
    public:
        Tienda();
        Tienda(string nombre);
        bool verificarProducto(int codigo);
        void agregarProducto();
        void mostrarProductos();
        void mostrarFacturas();
        void vender();
        void mostrarProductosCant();
        void mostrarProductosTipoVendidos();
        float calcularGanancia(Producto producto1, int cantidad);
        void mostrarUltimas3Ganancias();
        string getNombre();
        void setNombre(string nombre);
        float getGananciaTotal();
        void setGananciaTotal(float gananciaTotal);
        float getIVATotal();
        void setIVATotal(float ivaTotal);
};

#endif