#pragma once
#include "Producto.h"
#include <vector>
class CuidadoPersonal:public Producto
{
private:

	string fechaDeCaducidad;
	string marca;
	string tipoDeProducto;
	string recomendacionesDeUso;
public:
	CuidadoPersonal(int id, string nombre, string detalle, int cantidad, float precio,string fechaDeCaducidad,string marca,string tipoDeProducto,string recomendacionesDeUso);
	CuidadoPersonal(int id, string nombre, string detalle, int cantidad, int cantidadVendida, float precio, float precioDeCompra);

	void setFechaDeCaducidad(string fechaDeCaducidad);
	void setMarca(string marca2);
	void setTipoDeProducto(string tipoDeProducto);
	void setRecomendacionesDeUso(string recomendacionesDeUso);
	
	string getFechaDeCaducidad();
	string getMarca();
	string getTipoDeProducto();
	string getRecomendacionesDeUso();

};

