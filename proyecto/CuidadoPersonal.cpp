#include "CuidadoPersonal.h"

CuidadoPersonal::CuidadoPersonal(int id, string nombre, string detalle, int cantidad, float precio, string fechaDeCaducidad, string marca, string tipoDeProducto, string recomendacionesDeUso):Producto(id,nombre,detalle,cantidad,precio)
{
	this->fechaDeCaducidad = fechaDeCaducidad;
	this->marca = marca;
	this->tipoDeProducto = tipoDeProducto;
	this->recomendacionesDeUso = recomendacionesDeUso;
}

CuidadoPersonal::CuidadoPersonal(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioDeCompra) :Producto(id, nombre, detalle, cantidad, cantidadVendida, precio, precioDeCompra)
{

}

void CuidadoPersonal::setFechaDeCaducidad(string fechaDeCaducidad)
{
	this->fechaDeCaducidad = fechaDeCaducidad;
}

void CuidadoPersonal::setMarca(string marca2)
{
	this->marca = marca2;
}

void CuidadoPersonal::setTipoDeProducto(string tipoDeProducto)
{
	this->tipoDeProducto = tipoDeProducto;
}

void CuidadoPersonal::setRecomendacionesDeUso(string recomendacionesDeUso)
{
	this->recomendacionesDeUso = recomendacionesDeUso;
}

string CuidadoPersonal::getFechaDeCaducidad()
{
	return fechaDeCaducidad;
}

string CuidadoPersonal::getMarca()
{
	return marca;
}

string CuidadoPersonal::getTipoDeProducto()
{
	return tipoDeProducto;
}

string CuidadoPersonal::getRecomendacionesDeUso()
{
	return recomendacionesDeUso;
}
