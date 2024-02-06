#include "ArticuloDelHogar.h"

ArticuloDelHogar::ArticuloDelHogar(int id, string nombre, string detalle, int cantidad, float precio, string marca, string tipoDeArticulo, string materialDeFabricacion):Producto(id, nombre, detalle, cantidad, precio)
{
	this->marca = marca;
	this->tipoDeArticulo = tipoDeArticulo;
	this->materialDeFabricacion = materialDeFabricacion;
}

ArticuloDelHogar::ArticuloDelHogar(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioDeCompra) :Producto(id, nombre, detalle, cantidad, cantidadVendida, precio, precioDeCompra)
{

}
void ArticuloDelHogar::setTipoDeArticulo(string tipoDeArticulo)
{
	this->tipoDeArticulo = tipoDeArticulo;
}
void ArticuloDelHogar::setMarca(string marca2)
{
	this->marca = marca2;
}
void ArticuloDelHogar::setMaterialDeFabricacion(string materialDeFabricacion)
{
	this->materialDeFabricacion = materialDeFabricacion;
}
string ArticuloDelHogar::getMarca()
{
	return marca;
}

string ArticuloDelHogar::getTipoDeArticulo()
{
	return tipoDeArticulo;
}

string ArticuloDelHogar::getMaterialDeFabricacion()
{
	return materialDeFabricacion;
}
