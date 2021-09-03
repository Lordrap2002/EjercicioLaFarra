#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <stdlib.h>
#include "Tienda.h"

using std::cin;
using std::cout;

class View{
    private:
        Tienda laFarra;
        void mostrarMenuReportes();
    public:
        View();
        void mostrarMenu();
};

#endif