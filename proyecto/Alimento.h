#pragma once
#include "Producto.h"
class Alimento:public Producto
{
private:

	string fechaDeCaducidad;
	string marca;
	string tipoDeAlimento;
public:
	Alimento(int id, string nombre, string detalle, int cantidad, float precio,string fechaDeCaducidad,string marca,string tipoDeAlimento);
	Alimento(int id,string nombre,string detalle,int cantidad,int cantidadVendida,float precio,float precioDeCompra);
	
	void setFechaDeCaducidad(string fecha);
	void setMarca(string marca2);
	void setTipoDeAlimento(string tipoDeAlimento);
	string getFechaDeCaducidad();
	string getMarca();
	string getTipoDeAlimento();

};

