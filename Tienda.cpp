#include <iostream>
#include "Tienda.h"
#include <cstdio>

Tienda::Tienda(){
    this->nombre = "La Farra";
	this->ivaTotal = this->gananciaTotal = 0;
    this->contadorFacturas = 1;
    TipoProducto licor("Licor", 0.19), snack("Snack", 0.16);
    this->categorias[1] = licor;
    this->categorias[2] = snack;
    Producto producto1(licor, "Cerveza", 2500, 1800, 1, 10);
    Producto producto2(snack, "Papitas de limon", 3000, 1000, 2, 50);
    Producto producto3(snack, "Papitas de pollo", 3000, 1000, 3, 50);
    this->inventario[producto1.getCodigo()] = producto1;
    this->inventario[producto2.getCodigo()] = producto2;
    this->inventario[producto3.getCodigo()] = producto3;
}

Tienda::Tienda(string nombre){
    this->nombre = nombre;
    this->contadorFacturas = 1;
}

void Tienda::agregarDetalle(float &totalDelIVA, float &totalSinIVA, float &totalGeneral, Factura &factura){
    int codigo, cantidad;
	Producto producto1;
	float valorDelIVA, valorSinIVA, valorTotal; 
	do{
		cout << "Ingrese el codigo del producto: ";
		cin >> codigo;
	}while(!verificarProducto(codigo));
	producto1 = this->inventario[codigo];
	do{
		cout << "Ingrese la cantidad a comprar: ";
		cin >> cantidad;
	}while(cantidad <= 0 || cantidad > producto1.getCantUnidades());
	valorDelIVA = cantidad * producto1.getPrecio() * producto1.getTipoProducto().getIva();
	valorSinIVA = cantidad * producto1.getPrecio();
	valorTotal = valorSinIVA + valorDelIVA;
	DetalleFactura detalle1(producto1, cantidad, valorSinIVA, valorDelIVA, valorTotal);
	factura.agregarDetalle(detalle1);
	totalDelIVA += valorDelIVA;
	totalSinIVA += valorSinIVA;
	totalGeneral += valorTotal;
	this->inventario[codigo].setCantUnidades(producto1.getCantUnidades() - cantidad);
	this->gananciaTotal += calcularGanancia(producto1, cantidad);
}

bool Tienda::verificarProducto(int codigo){
    return this->inventario.find(codigo) != this->inventario.end() ? true : false;
}

void Tienda::agregarProducto(){
    string nombre;
	float costo, precio;
	int codigo, cantUnidades, codigoTipoProducto;
    bool existeProducto = true;
	cout << "Ingrese el nombre del producto: ";
	cin.ignore(100, '\n');
    getline(cin, nombre);
    cout << "Ingrese el codigo del tipo de producto(1 = licor, 2 = snack): ";
	cin >> codigoTipoProducto;
	do{
	    cout << "Ingrese el costo de compra del producto : ";
		cin >> costo;
		cout << "Ingrese el precio al que va a vender el producto : ";
		cin >> precio;
        cout << "Ingrese la cantidades de unidades disponibles : ";
		cin >> cantUnidades;
	}while(costo < 0 || precio < 0 || cantUnidades < 0);	
	do{
	    cout << "Ingrese la identificacion del producto : ";
		cin >> codigo;
		if(!verificarProducto(codigo)){
			existeProducto = false;
		}
	}while(existeProducto);
    Producto producto1(this->categorias[codigoTipoProducto], nombre, precio, costo, codigo, cantUnidades);
	inventario[codigo] = producto1;
}

void Tienda::mostrarProductos(){
    for(map<int, Producto>::iterator pProducto = inventario.begin(); pProducto != inventario.end(); pProducto++){
		Producto valor = pProducto->second;
		valor.mostrarProducto();
	}
}

void Tienda::mostrarFacturas(){
	int i = 1;
    for(vector<Factura>::iterator pFactura = facturas.begin(); pFactura != facturas.end(); pFactura++, i++){
		cout << ">>>>>>>>>>>>>>>>>>>>>\nFactura #" << i << endl; 
		pFactura->mostrarFactura();
	}
}

void Tienda::vender(){
	float totalDelIVA = 0, totalSinIVA =0, totalGeneral = 0;
	int opcion;
	string fecha;
	Factura factura1;
	cout << "Ingrese la fecha actual (dd-mm-aaaa): ";
	cin >> fecha;
	factura1.setFecha(fecha);
	factura1.setCodigo(this->contadorFacturas++);
	do{
		cout << "Ingrese 1 para continuar o -1 para salir: ";
		cin >> opcion;
		if(opcion + 1){
			agregarDetalle(totalDelIVA, totalSinIVA, totalGeneral, factura1);
		}
	}while(opcion + 1);
	factura1.setValorTotalSinIVA(totalSinIVA);
	factura1.setValorTotalDelIVA(totalDelIVA);
	factura1.setValorTotal(totalGeneral);
	this->facturas.push_back(factura1);
	this->ivaTotal += totalDelIVA;
}

void Tienda::mostrarProductosCant(){
	int cantidad;
	cout << "Ingrese la cantidad: ";
	cin >> cantidad;
	for(map<int, Producto>::iterator pProducto = inventario.begin(); pProducto != inventario.end(); pProducto++){
		Producto valor = pProducto->second;
		if(valor.getCantUnidades() < cantidad){
			valor.mostrarProducto();
		}	
	}
}

void Tienda::mostrarProductosTipoVendidos(){
	int cantSnacks = 0, cantLicor = 0;
	for(vector<Factura>::iterator pFactura = facturas.begin(); pFactura != facturas.end(); pFactura++){
		for(vector<DetalleFactura>::iterator pDetalle = pFactura->getDetalles().begin(); pDetalle != pFactura->getDetalles().end(); pDetalle++){
			DetalleFactura detalle1 = *pDetalle;
			if(detalle1.getProducto().getTipoProducto().getNombre() == categorias[2].getNombre()){
				cantSnacks += detalle1.getCantUnidVend();
			}else{
				cantLicor += detalle1.getCantUnidVend();
			}	
		}
	}
	cout << "Numero de productos tipo Snack vendidos: " << cantSnacks << ".\n";
	cout << "Numero de productos tipo Licor vendidos: " << cantLicor << ".\n";
}

float Tienda::calcularGanancia(Producto producto1, int cantidad){
	return (producto1.getPrecio() - producto1.getCosto()) * cantidad; 
}

void Tienda::mostrarUltimas3Ganancias(){
	int i = 0, valor = facturas.size() - 3;
	float ganancias = 0;
	for(vector<Factura>::iterator pFactura = facturas.begin() + valor; i < 3; i++, pFactura++){
		for(vector<DetalleFactura>::iterator pDetalle = pFactura->getDetalles().begin(); pDetalle != pFactura->getDetalles().end(); pDetalle++){
			DetalleFactura detalle1 = *pDetalle;
			ganancias += calcularGanancia(detalle1.getProducto(), detalle1.getCantUnidVend());
		}
	}
	cout << "Las ultimas 3 ganancias son: " << ganancias << ".\n";
}


string Tienda::getNombre(){
    return this->nombre;
}

void Tienda::setNombre(string nombre){
    this->nombre = nombre;
}

float Tienda::getGananciaTotal(){
	return this->gananciaTotal;
}

void Tienda::setGananciaTotal(float gananciaTotal){
	this->gananciaTotal = gananciaTotal;
}

float Tienda::getIVATotal(){
	return this->ivaTotal;
}

void Tienda::setIVATotal(float ivaTotal){
	this->ivaTotal = ivaTotal;
}


