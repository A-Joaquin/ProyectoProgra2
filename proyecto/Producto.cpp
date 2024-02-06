#include "Producto.h"

Producto::Producto(int id, string nombre, string detalle ,int cantidad, float precio)
{
	this->id = id;
	this->nombre = nombre;
	this->cantidad = cantidad;
	this->precio = precio;
	this->detalle = detalle;
}

Producto::Producto(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioCompra)
{
	this->id = id;
	this->nombre = nombre;
	this->cantidad = cantidad;
	this->cantidadVendida = cantidadVendida;
	this->precio = precio;
	this->detalle = detalle;
	this->precioDeCompra = precioCompra;
}

void Producto::añadirProveedor(Proveedor* proveedorDeProducto)
{
	this->proveedorDeProducto = proveedorDeProducto;
}

int Producto::getId()
{
	return id;
}

float Producto::getPrecio()
{
	return precio;
}

int Producto::getCantidad()
{
	return cantidad;
}

string Producto::getDatosProducto()
{
	return "id: " + to_string(id) + " Nombre: " + nombre + " Precio : " + to_string(precio) ;
}

string Producto::getDetalle()
{
	return detalle;
}

string Producto::getNombre()
{
	return nombre;
}

void Producto::disminuirUnaUnidad()
{
	this->cantidad = cantidad - 1;
}

void Producto::disminuirCantidad(int cantidad2)
{
	this->cantidad = cantidad - cantidad2;
}

void Producto::setCantidad(int cantidad1)
{
	this->cantidad = cantidad1;
}

void Producto::aumentarCantidad(int cantidad2)
{
	this->cantidad = cantidad + cantidad2;
}

void Producto::agregarPrecioCompra(float precioDeCompra)
{
	this->precioDeCompra = precioDeCompra;
}

int Producto::getPrecioCompra()
{
	return precioDeCompra;
}

void Producto::setTieneDescuento()
{
	this->tieneDescuento = 1;
}

bool Producto::getTieneDescuento()
{
	return tieneDescuento;
}

void Producto::setPrecioFinal(float precioFINAL)
{
	this->precioConDescuento = precioFINAL;
}

float Producto::getPrecioFinal()
{
	return precioConDescuento;
}

void Producto::aumentarCantidadVendida(int cantidadVendida2)
{
	this->cantidadVendida = cantidadVendida + cantidadVendida2;
}

int Producto::getCantidadVendida()
{
	return cantidadVendida;
}

Proveedor* Producto::getProveedor()
{
	return proveedorDeProducto;
}

int Producto::getIdProveedor()
{
	return idProveedorLoadData;
}

void Producto::setIdProveedor(int idP)
{
	this->idProveedorLoadData = idP;
}


