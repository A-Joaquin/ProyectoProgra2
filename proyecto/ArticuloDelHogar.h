#pragma once
#include "Producto.h"
class ArticuloDelHogar:public Producto
{
private:
	string marca;
	string tipoDeArticulo;
	string materialDeFabricacion;


public:
	ArticuloDelHogar(int id, string nombre, string detalle, int cantidad, float precio,string marca,string tipoDeArticulo,string materialDeFabricacion);
	ArticuloDelHogar(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioDeCompra);

	void setTipoDeArticulo(string tipoDeArticulo);
	void setMarca(string marca2);
	void setMaterialDeFabricacion(string materialDeFabricacion);

	string getMarca();
	string getTipoDeArticulo();
	string getMaterialDeFabricacion();
};

