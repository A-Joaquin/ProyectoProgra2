#pragma once
#include <string>


#include "Proveedor.h"
#include "IProducto.h"
using namespace std;

class Proveedor;

class Producto: public IProducto
{
protected:

	int id;
	string nombre;
	string detalle;
	int cantidad;
	int cantidadVendida=0;
	float precioConDescuento=0;
	float precio;
	float precioDeCompra;
	Proveedor* proveedorDeProducto;
	bool tieneDescuento = 0;
	int idProveedorLoadData;
public:
	Producto(int id,string nombre, string detalle,int cantidad,float precio);
	Producto(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioCompra);
	void añadirProveedor(Proveedor* proveedorDeProducto);
	int getId() override;
	float getPrecio() override;
	int getCantidad() override;
	string getDatosProducto() override;
	string getDetalle() override;
	string getNombre() override;
	void disminuirUnaUnidad() override;
	void disminuirCantidad(int cantidad2) override;
	void setCantidad(int cantidad1) override;
	void aumentarCantidad(int cantidad2) override;
	void agregarPrecioCompra(float precioDeCompra) override;
	int getPrecioCompra() override;
	void setTieneDescuento() override;
	bool getTieneDescuento() override;
	void setPrecioFinal(float precioFINAL) override;
	float getPrecioFinal() override;
	void aumentarCantidadVendida(int cantidadVendida2) override;
	int getCantidadVendida() override;
	Proveedor* getProveedor();
	int getIdProveedor();
	void setIdProveedor(int idP);
};

