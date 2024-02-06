#pragma once
#include <string>
#include <fstream>
#include "Producto.h"
#include "Alimento.h"
#include "ArticuloDelHogar.h"
#include "CuidadoPersonal.h"
#include <iostream>
#include "Empleado.h"
#include "Cliente.h"
#include "CajaRegistradora.h"
#include "Factura.h"
#include "Transaccion.h"
using namespace std;
class SaveData
{
public:
	static void guardarDatos(string archivo, vector<Producto*> productos);
    static void guardarClientes(const string& archivo, const vector<Cliente*>& clientes);
    static void guardarEmpleados(const string& archivo, const vector<Empleado*>& empleados);
    static void guardarProvedores(string archivo, vector<Proveedor*> proveedores);
    static void guardarCajas(string archivo, vector<CajaRegistradora*> cajas);
    static void guardarFacturas(string archivo, vector<Factura*> facturas);
    static void guardarTransacciones(string archivoGuarda, vector<Transaccion*> Transacciones);


};