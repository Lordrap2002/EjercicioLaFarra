all: compilar
compilar: tienda producto tipoproducto factura detallefactura view main
		g++ -o Salida tienda.o producto.o tipoproducto.o factura.o detallefactura.o view.o Main.o 
tienda: Tienda.cpp Tienda.h
		g++ -c Tienda.cpp
producto: Producto.cpp Producto.h
		g++ -c Producto.cpp
tipoproducto: TipoProducto.cpp TipoProducto.h
		g++ -c TipoProducto.cpp
factura: Factura.cpp Factura.h
		g++ -c Factura.cpp
detallefactura: DetalleFactura.cpp DetalleFactura.h
		g++ -c DetalleFactura.cpp
view: View.cpp View.h
		g++ -c View.cpp
main: Main.cpp Tienda.h Producto.h TipoProducto.h Factura.h DetalleFactura.h View.h
		g++ -c Main.cpp
