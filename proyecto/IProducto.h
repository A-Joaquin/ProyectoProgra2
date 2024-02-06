#pragma once
#include <string>
using namespace std;
class IProducto
{
public:
	virtual string getDatosProducto()=0;
	virtual string getDetalle() = 0;
	virtual string getNombre() =0;
	virtual void disminuirUnaUnidad() = 0;
	virtual void disminuirCantidad(int cantidad2) = 0;
	virtual void setCantidad(int cantidad1) = 0;
	virtual void aumentarCantidad(int cantidad2) = 0;
	virtual void agregarPrecioCompra(float precioDeCompra) = 0;
	virtual int getPrecioCompra() = 0;
	virtual void setPrecioFinal(float precioFINAL) = 0;
	virtual float getPrecioFinal() = 0;
	virtual void aumentarCantidadVendida(int cantidadVendida2) = 0;
	virtual int getCantidadVendida() = 0;
	virtual void setTieneDescuento() = 0;
	virtual bool getTieneDescuento() = 0;
	virtual int getId() = 0;
	virtual float getPrecio() = 0;
	virtual int getCantidad() = 0;


	~IProducto()
	{
	}

};
