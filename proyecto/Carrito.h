#pragma once
#include "Producto.h"
#include <vector>
#include "Descuento.h"
class Carrito
{
private:
	vector<Producto*> productosCarrito;
	float total=0;
	vector<Descuento*> descuentos;
	bool cancelarCompra=0;
	vector<int> cantidadesParaLlevar;
public:
	Carrito();
	void vaciarCarrito();
	void agregarProducto(Producto* producto);
	float getTotal();
	void calcularTotal();
	void setCantidadesParaLlevar(vector<int> cantidadesParaLlevar);
	float verificarDescuentoDeProducto(int id);

	vector<Producto*>& getCarrito();

	void agregarDescuentos(vector<Descuento*> descuentos1);
	void cancelarCompraDeCarrito();
	bool getCancelarCompra();
};

