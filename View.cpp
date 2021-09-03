#include "View.h"

View::View(){}

void View::mostrarMenuReportes(){
    int opcion;
    do{
        printf("Menu Reportes:\n"
               "1. Mostrar productos por cantidad.\n"
               "2. Mostrar productos por TipoProducto.\n"
               "3. Mostar ganancias.\n"
               "4. Ver todos los productos.\n"
               "5. Valor a pagar por IVA a la DIAN.\n"
               "0. Salir.\n"
               "Opcion: ");
        cin >> opcion;
        switch(opcion){
        case 1:
            laFarra.mostrarProductosCant();
            break;
        case 2:
            laFarra.mostrarProductosTipoVendidos();
            break;
        case 3:
            cout << "Las ganancias son: " << laFarra.getGananciaTotal() << ".\n";
            break;
        case 4:
            laFarra.mostrarProductos();
            break;
        case 5:
            cout << "El valor a pagar por IVA a la DIAN es:" << laFarra.getIVATotal() << ".\n";
            break;
        }
    }while(opcion);
}

void View::mostrarMenu(){
    int opcion;
    do{
        printf("Menu Tienda:\n"
               "1. Agregar Producto.\n"
               "2. Mostrar Productos.\n"
               "3. Vender.\n"
               "4. Mostrar Ventas.\n"
               "5. Reportes.\n"
               "6. Mostrar ultimas 3 ganancias.\n"
               "0. Salir.\n"
               "Opcion: ");
        cin >> opcion;
        switch(opcion){
        case 1:
            laFarra.agregarProducto();
            break;
        case 2:
            laFarra.mostrarProductos();
            break;
        case 3:
            laFarra.vender();
            break;
        case 4:
            laFarra.mostrarFacturas();
            break;
        case 5:
            mostrarMenuReportes();
            break;
        case 6:
            laFarra.mostrarUltimas3Ganancias();
            break;
        }

    }while(opcion);
}