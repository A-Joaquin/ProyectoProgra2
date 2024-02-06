#include "Descuento.h"
Descuento::Descuento(int id, Producto* producto, float porcentajeDescuento, string fechaInicio, string fechaFin)
{
    this->id = id;
    this->producto = producto;
    this->porcentajeDescuento = porcentajeDescuento;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
}

float Descuento::getDescuento()
{
    return this->porcentajeDescuento;
}

int Descuento::getIdProducto()
{
    return producto->getId();
}
