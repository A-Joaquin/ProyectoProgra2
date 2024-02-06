#include "Alimento.h"

Alimento::Alimento(int id, string nombre, string detalle, int cantidad, float precio, string fechaDeCaducidad, string marca, string tipoDeAlimento):Producto(id, nombre, detalle, cantidad, precio)
{
	this->fechaDeCaducidad = fechaDeCaducidad;
	this->marca = marca;
	this->tipoDeAlimento = tipoDeAlimento;
}

Alimento::Alimento(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioDeCompra) :Producto( id,  nombre,  detalle,  cantidad,  cantidadVendida,  precio, precioDeCompra)
{
	
}

void Alimento::setFechaDeCaducidad(string fecha)
{
	this->fechaDeCaducidad = fecha;
}

void Alimento::setMarca(string marca2)
{
	this->marca = marca2;
}

void Alimento::setTipoDeAlimento(string tipoDeAlimento)
{
	this->tipoDeAlimento = tipoDeAlimento;
}

string Alimento::getFechaDeCaducidad()
{
	return fechaDeCaducidad;
}

string Alimento::getMarca()
{
	return marca;
}

string Alimento::getTipoDeAlimento()
{
	return tipoDeAlimento;
}
