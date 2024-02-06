#include "SaveData.h"

void SaveData::guardarDatos(string archivo2,vector<Producto*> productos)
{
    ofstream archivo(archivo2);
    if (archivo.is_open()) {
        // Iterar sobre el vector de productos y guardar los atributos en el archivo
        for (const auto& producto : productos) {
            archivo << "ID: " << producto->getId() << endl;
            archivo << "Nombre: " << producto->getNombre() << endl;
            archivo << "Detalle: " << producto->getDetalle() << endl;
            archivo << "cantidad: " << producto->getCantidad() << endl;
            archivo << "cantidadVendida: " << producto->getCantidadVendida() << endl;
            archivo << "precio: " << producto->getPrecio() << endl;
            archivo << "precioDeCompra: " << producto->getPrecioCompra() << endl;
            archivo << "idProv: " << producto->getProveedor()->getId();
            // Guardar los atributos específicos de cada clase derivada

            if (dynamic_cast<Alimento*>(producto)) {
                Alimento* alimento = dynamic_cast<Alimento*>(producto);
                archivo << "Tipo: Alimento" << endl;
                archivo << "Fecha de caducidad: " << alimento->getFechaDeCaducidad() << endl;
                archivo << "Marca: " << alimento->getMarca() << endl;
                archivo << "Tipo de alimento: " << alimento->getTipoDeAlimento() << endl;
            }
            else if (dynamic_cast<ArticuloDelHogar*>(producto)) {
                ArticuloDelHogar* articulo = dynamic_cast<ArticuloDelHogar*>(producto);
                archivo << "Tipo: Artículo del Hogar" << endl;
                archivo << "Marca: " << articulo->getMarca() << endl;
                archivo << "Tipo de artículo: " << articulo->getTipoDeArticulo() << endl;
                archivo << "Material de fabricación: " << articulo->getMaterialDeFabricacion() << endl;
            }
            else if (dynamic_cast<CuidadoPersonal*>(producto)) {
                CuidadoPersonal* cuidado = dynamic_cast<CuidadoPersonal*>(producto);
                archivo << "Tipo: Cuidado Personal" << endl;
                archivo << "Fecha de caducidad: " << cuidado->getFechaDeCaducidad() << endl;
                archivo << "Marca: " << cuidado->getMarca() << endl;
                archivo << "Tipo de producto: " << cuidado->getTipoDeProducto() << endl;
                archivo << "Ingredientes: ";
                archivo << "Recomendaciones de uso: " << cuidado->getRecomendacionesDeUso() << endl;
            }
            
            archivo << endl;
        }
        // Cerrar el archivo
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void SaveData::guardarClientes(const string& archivo, const vector<Cliente*>& clientes)
{
    ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const auto& cliente : clientes) {
            archivoSalida << "ID: " << cliente->getId() << endl;
            archivoSalida << "Nombre: " << cliente->getNombre() << endl;
            archivoSalida << "Edad: " << cliente->getEdad() << endl;
            archivoSalida << "Dirección: " << cliente->getDireccion() << endl;
            archivoSalida << "Teléfono: " << cliente->getTelefono() << endl;
            archivoSalida << "Correo Electrónico: " << cliente->getCorreoElectronico() << endl;
            // Guardar atributos específicos de Cliente
            archivoSalida << "Puntos: " << cliente->getPuntos() << endl;
            archivoSalida << "Transacciones:" << endl;
            for (Transaccion* Transaccion : cliente->getTransaccion()) {
                archivoSalida << Transaccion->getId() << endl;
            }
            archivoSalida << endl;
        }
        archivoSalida.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void SaveData::guardarEmpleados(const string& archivo, const vector<Empleado*>& empleados)
{
    ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const auto& empleado : empleados) {
            archivoSalida << "ID: " << empleado->getId() << endl;
            archivoSalida << "Nombre: " << empleado->getNombre() << endl;
            archivoSalida << "Edad: " << empleado->getEdad() << endl;
            archivoSalida << "Dirección: " << empleado->getDireccion() << endl;
            archivoSalida << "Teléfono: " << empleado->getTelefono() << endl;
            archivoSalida << "Correo Electrónico: " << empleado->getCorreoElectronico() << endl;
            // Guardar atributos específicos de Empleado
            archivoSalida << "Cargo: " << empleado->obtenerCargo() << endl;
            archivoSalida << "Salario: " << empleado->getSalario() << endl;
            archivoSalida << "Horario: " << empleado->getHorario() << endl;
            archivoSalida << "Estado: " << empleado->obtenerEstado() << endl;
            archivoSalida << endl;
        }
        archivoSalida.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void SaveData::guardarProvedores(string archivo, vector<Proveedor*> proveedores)
{
    ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const auto& proveedor : proveedores) {
            archivoSalida << "id: " << proveedor->getId() << endl;
            archivoSalida << "nombre: " << proveedor->getNombre() << endl;
            archivoSalida << "direccion: " << proveedor->getDireccion() << endl;
            archivoSalida << "telefono: " << proveedor->getTelefono() << endl;
            archivoSalida << "IdProductos" << endl;
            for (int i = 0; i < proveedor->getProductos().size(); i++)
            {
                archivoSalida<<proveedor->getProductos()[i]->getId()<<endl;
            }
            archivoSalida << endl;
        }
        archivoSalida.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void SaveData::guardarCajas(string archivo, vector<CajaRegistradora*> cajas)
{
    ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const auto& caja : cajas) {
            archivoSalida << "id: " << caja->getId() << endl;
            archivoSalida << "Transacciones" << endl;
            for (int i = 0; i < caja->getTransacciones().size(); i++)
            {
                archivoSalida << caja->getTransacciones()[i]->getId() << endl;
            }
            archivoSalida << endl;
        }
        archivoSalida.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void SaveData::guardarFacturas(string archivo, vector<Factura*> facturas)
{
    ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const auto& factura : facturas) {
            archivoSalida << "id: " << factura->getId() << endl;
            archivoSalida << "nit: " << factura->getNit() << endl;
            archivoSalida << "nombre: " << factura->getNombre() << endl;
            archivoSalida << "IdT: " << factura->getTransaccion()->getId() << endl;
            archivoSalida << endl;
        }
        archivoSalida.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void SaveData::guardarTransacciones(string archivoGuarda, vector<Transaccion*> Transacciones)
{
    ofstream archivo(archivoGuarda);
    if (archivo.is_open())
    {
        for (const auto& transaccion : Transacciones) {
            archivo << "id: " << transaccion->getId() << endl;
            archivo << "monto: " << transaccion->getMonto() << endl;
            archivo << "fecha: " << transaccion->getFecha().obtenerFechaActual() << endl;
            archivo << "clienteId: " << transaccion->getCliente()->getId()<<endl;
            archivo << "empleadoId: " << transaccion->getEmpleado()->getId() << endl;
            archivo << "Carrito:" << endl;
            for (int i = 0; i < transaccion->getCarrito().getCarrito().size(); i++)
            {
                archivo<<transaccion->getCarrito().getCarrito()[i]->getId()<<endl;
            }
            archivo << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
