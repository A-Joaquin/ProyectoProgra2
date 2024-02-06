#include "Carrito.h"

Carrito::Carrito()
{

}

void Carrito::vaciarCarrito()
{

	productosCarrito.clear();

}

void Carrito::agregarProducto(Producto* producto)
{
	productosCarrito.push_back(producto);
}

float Carrito::getTotal()
{
	return total;
}

void Carrito::calcularTotal()
{
	float descuento = 0;
	float precioConDescuento=0;
	for (int i = 0; i < productosCarrito.size(); i++)
	{
		descuento = verificarDescuentoDeProducto(productosCarrito[i]->getId());
		precioConDescuento=productosCarrito[i]->getPrecio() - descuento * productosCarrito[i]->getPrecio();
		total = total + precioConDescuento;
		productosCarrito[i]->setPrecioFinal(precioConDescuento);
		if (descuento > 0)
		{
			
			productosCarrito[i]->setTieneDescuento();
		}

	}
}

void Carrito::setCantidadesParaLlevar(vector<int> cantidadesParaLlevar)
{
	this->cantidadesParaLlevar = cantidadesParaLlevar;
}

float Carrito::verificarDescuentoDeProducto(int id)
{
	float precioConDescuento=0;
	for (int i = 0; i < descuentos.size(); i++)
	{
		if (id == descuentos[i]->getIdProducto())
		{
			precioConDescuento=descuentos[i]->getDescuento();
		}
	}
	return precioConDescuento;
}

vector<Producto*>& Carrito::getCarrito()
{
	return productosCarrito;
}

void Carrito::agregarDescuentos(vector<Descuento*> descuentos1)
{
	this->descuentos = descuentos1;
}

void Carrito::cancelarCompraDeCarrito()
{
	this->cancelarCompra = 1;
}

bool Carrito::getCancelarCompra()
{
	return cancelarCompra;
}

