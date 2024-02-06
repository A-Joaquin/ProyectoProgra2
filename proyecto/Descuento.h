#pragma once
#include "Producto.h"
class Descuento
{
private:
	int id;
	Producto* producto;
	float porcentajeDescuento;
	string fechaInicio;
	string fechaFin;
public:
	
	Descuento(int id,Producto* producto,float porcentajeDescuento,string fechaInicio,string fechaFin);
	float getDescuento();
	int getIdProducto();



};

