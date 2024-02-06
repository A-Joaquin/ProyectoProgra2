#include "LoadData.h"

LoadData::LoadData()
{
}

void LoadData::recuperarDatos(string archivoProductos, string archivoClientes, string archivoEmpleado, string archivoProveedores, string archivoCajas, string archivoFacturas, string archivoTransacciones, string archivoTransacciones2)
{
    productos=cargarDatos(archivoProductos);
    clientes=recuperarClientes(archivoClientes);
    empleados = recuperarEmpleados(archivoEmpleado);
    proveedores = recuperarProveedores(archivoProveedores);
    ComplementarProducto_Proveedor();

    trasacciones1 = recuperarTransacciones(archivoTransacciones);
    trasacciones2 = recuperarTransacciones(archivoTransacciones2);
    //cout << "-------" << endl;
    //for (int i = 0; i < trasacciones1.size(); i++)
    //{
    //    cout << "id1: " << trasacciones1[i]->getId() << endl;;
    //}

    ////cout << "transacciones2" << endl;
    //for (int i = 0; i < trasacciones2.size(); i++)
    //{
    //    cout << "id: " << trasacciones2[i]->getId() << endl;;
    //}


    cajas = recuperarCajas(archivoCajas);
    //cout << "---------------" << endl;
    //cout << "nrocajas: " << cajas.size() << endl;
    //for (int i = 0; i < cajas.size(); i++)
    //{
    //    cout << "id: " << cajas[i]->getId() << endl;;
    //}

    ComplementarCliente_transaccion();
    //for (int i = 0; i < clientes.size(); i++)
    //{
    //    if (clientes[i]->getTransaccion().size() > 0)
    //    {
    //        cout<<clientes[i]->getTransaccion()[clientes[i]->getTransaccion().size()]->getId()<<endl;
    //    }
    //    cout << "id: " <<  << endl;
    //}

    facturas = recuperarFacturas(archivoFacturas);
    
}



vector<Producto*> LoadData::cargarDatos(string archivo2)
{
    vector<Producto*> productos;

    ifstream archivo(archivo2);
    if (archivo.is_open()) {
        // Variables temporales para almacenar los datos recuperados


        // Iterar sobre las líneas del archivo
        string linea;
        int id,idP=0;
        string nombre;
        string detalle;
        int cantidad=0;
        int cantidadVendida=0;
        float precio=0;
        float precioDeCompra=0;
        string tipo;
        while (getline(archivo, linea)) {
            // Recuperar los atributos comunes
            if (linea.find("ID:") != string::npos) {
                id = stoi(linea.substr(linea.find(":") + 1));
            }
            else if (linea.find("Nombre:") != string::npos) {
                nombre = linea.substr(linea.find(":") + 1);
            }
            else if (linea.find("Detalle:") != string::npos) {
                detalle = linea.substr(linea.find(":") + 1);
            }
            else if (linea.find("cantidad:") != string::npos) {
                cantidad = stoi(linea.substr(linea.find(":") + 1));
            }
            else if (linea.find("cantidadVendida:") != string::npos) {
                cantidadVendida = stoi(linea.substr(linea.find(":") + 1));
            }
            else if (linea.find("precio:") != string::npos) {
                precio = stof(linea.substr(linea.find(":") + 1));
            }
            else if (linea.find("precioDeCompra:") != string::npos) {
                precioDeCompra = stof(linea.substr(linea.find(":") + 1));
            }
            else if (linea.find("idProv:") != string::npos) {
                idP = stof(linea.substr(linea.find(":") + 1));;

            }

            // Determinar el tipo de producto y crear objetos correspondientes
            if (linea.find("Tipo: Alimento") != string::npos) {
                Alimento* alimento = new Alimento(id, nombre, detalle, cantidad, cantidadVendida, precio, precioDeCompra);
                // Recuperar los atributos específicos de Alimento
                getline(archivo, linea); // Fecha de caducidad
                alimento->setFechaDeCaducidad(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Marca
                alimento->setMarca(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Tipo de alimento
                alimento->setTipoDeAlimento(linea.substr(linea.find(":") + 1));

                // Agregar el objeto al vector de productos
                alimento->setIdProveedor(idP);
                productos.push_back(alimento);
            }
            else if (linea.find("Tipo: Artículo del Hogar") != string::npos) {
                ArticuloDelHogar* articulo = new ArticuloDelHogar(id, nombre, detalle, cantidad, cantidadVendida, precio, precioDeCompra);
                // Recuperar los atributos específicos de ArticuloDelHogar
                getline(archivo, linea); // Marca
                articulo->setMarca(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Tipo de artículo
                articulo->setTipoDeArticulo(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Material de fabricación
                articulo->setMaterialDeFabricacion(linea.substr(linea.find(":") + 1));
                articulo->setIdProveedor(idP);
                // Agregar el objeto al vector de productos
                productos.push_back(articulo);
            }
            else if (linea.find("Tipo: Cuidado Personal") != string::npos) {
                CuidadoPersonal* cuidado = new CuidadoPersonal(id, nombre, detalle, cantidad, cantidadVendida, precio, precioDeCompra);
                // Recuperar los atributos específicos de CuidadoPersonal
                getline(archivo, linea); // Fecha de caducidad
                cuidado->setFechaDeCaducidad(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Marca
                cuidado->setMarca(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Tipo de producto
                cuidado->setTipoDeProducto(linea.substr(linea.find(":") + 1));
                getline(archivo, linea); // Recomendaciones de uso
                cuidado->setRecomendacionesDeUso(linea.substr(linea.find(":") + 1));
                cuidado->setIdProveedor(idP);
                // Agregar el objeto al vector de productos
                productos.push_back(cuidado);
            }
        }
        // Cerrar el archivo
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return productos;
}

vector<Cliente*> LoadData::recuperarClientes( string archivo)
{
    vector<Cliente*> clientes;
    vector<int> idVentas;
    ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        Cliente* cliente = nullptr;
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("ID: ") != string::npos) {
                cliente = new Cliente();
                cliente->setId(stoi(linea.substr(4)));
            }
            else if (linea.find("Nombre: ") != string::npos) {
                cliente->setNombre(linea.substr(8));
            }
            else if (linea.find("Edad: ") != string::npos) {
                cliente->setEdad(stoi(linea.substr(6)));
            }
            else if (linea.find("Dirección: ") != string::npos) {
                cliente->setDireccion(linea.substr(12));
            }
            else if (linea.find("Teléfono: ") != string::npos) {
                cliente->setTelefono(stoi(linea.substr(10)));
            }
            else if (linea.find("Correo Electrónico: ") != string::npos) {
                cliente->setCorreoElectronico(linea.substr(20));
            }
            else if (linea.find("Puntos: ") != string::npos) {
                cliente->setPuntos(stoi(linea.substr(8)));
            }
            else if (linea == "Transacciones:") {
                //cout << "entroooooooooooooooo" << endl;
                // Iniciar la lectura de los productos
                while (getline(archivoEntrada, linea) && !linea.empty()) {
                    int idTransaccion=(stoi(linea));
                    idVentas.push_back(idTransaccion);
                    //cout << "nro ventas id recuperado: " << idVentas.size() << endl;
                    // Aquí debes recuperar el producto correspondiente al ID
                }
            }

            if (linea.empty()) {
                if (cliente != nullptr)
                {
                    //cout <<"idi ventas recuperado: "<< idVentas.size() << endl;;
                    cliente->setIdvENTAS(idVentas);
                    clientes.push_back(cliente);
                    idVentas.clear();
                    cliente = nullptr;
                }

            }
        }
        archivoEntrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return clientes;
}

vector<Empleado*> LoadData::recuperarEmpleados(string archivo)
{
    vector<Empleado*> empleados;

    ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        Empleado* empleado = nullptr;
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("ID: ") != string::npos) {
                empleado = new Empleado();
                empleado->setId(stoi(linea.substr(4)));
            }
            else if (linea.find("Nombre: ") != string::npos) {
                empleado->setNombre(linea.substr(8));
            }
            else if (linea.find("Edad: ") != string::npos) {
                empleado->setEdad(stoi(linea.substr(6)));
            }
            else if (linea.find("Dirección: ") != string::npos) {
                empleado->setDireccion(linea.substr(12));
            }
            else if (linea.find("Teléfono: ") != string::npos) {
                empleado->setTelefono(stoi(linea.substr(10)));
            }
            else if (linea.find("Correo Electrónico: ") != string::npos) {
                empleado->setCorreoElectronico(linea.substr(20));
            }
            else if (linea.find("Cargo: ") != string::npos) {
                empleado->setCargo(linea.substr(7));
            }
            else if (linea.find("Salario: ") != string::npos) {
                empleado->setSalario(stof(linea.substr(9)));
            }
            else if (linea.find("Horario: ") != string::npos) {
                empleado->setHorario(linea.substr(9));
            }
            else if (linea.find("Estado: ") != string::npos) {
                empleado->setEstado(linea.substr(8));
            }
            else if (linea.empty()) {
                empleados.push_back(empleado);
                empleado = nullptr;
            }
        }
        archivoEntrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return empleados;
}

vector<Proveedor*> LoadData::recuperarProveedores(string archivo) 
{   
    vector<Proveedor*> proveedores;
    vector<int> idProductos;
    ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        Proveedor* proveedor = nullptr;
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("id: ") != string::npos) {
                proveedor = new Proveedor();
                proveedor->setId(stoi(linea.substr(4)));
            }
            else if (linea.find("nombre: ") != string::npos) {
                proveedor->setNombre(linea.substr(8));
            }
            else if (linea.find("direccion: ") != string::npos) {
                proveedor->setDireccion(linea.substr(11));
            }
            else if (linea.find("telefono: ") != string::npos) {
                proveedor->setTelefono(stoi(linea.substr(10)));
            }
            else if (linea == "IdProductos") {
                // Iniciar la lectura de los productos
                while (getline(archivoEntrada, linea) && !linea.empty()) {
                    idProductos.push_back(stoi(linea));
                    //cout << stoi(linea) << endl;
                    //cout << "id producto guardado" << endl;
                    // Aquí debes recuperar el producto correspondiente al ID
                }
            }
            if (linea.empty()) {
                if (proveedor != nullptr) {
                    proveedor->setIdProductos(idProductos);
                    proveedores.push_back(proveedor);
                    proveedor = nullptr;
                    idProductos.clear();
                    //cout << "proveedor guardado" << endl;
                }
            }
            
        }
        archivoEntrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return proveedores;
}
vector<CajaRegistradora*> LoadData::recuperarCajas(string archivo)
{
    vector<CajaRegistradora*> cajas;
    int transaccionId=0;
    ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        CajaRegistradora* caja = nullptr;
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("id: ") != string::npos) {
                caja = new CajaRegistradora();
                caja->setId(stoi(linea.substr(4)));
            }
            else if (linea.find("Transacciones") != string::npos) {
                getline(archivoEntrada, linea);
                while (!linea.empty()) {
                    transaccionId = stoi(linea);
                    
                    getline(archivoEntrada, linea);
                }
            }
            if (linea.empty()) {
                int posTransaccion = 0;
                if (buscarTransaccion1(transaccionId))
                {
                    posTransaccion = buscarTransaccion1(transaccionId);
                    if (posTransaccion != -1)
                    {
                        caja->agregarTransaccion(trasacciones1[posTransaccion]);
                    }
                    
                }
                if (buscarTransaccion2(transaccionId))
                {
                    posTransaccion = buscarTransaccion2(transaccionId);
                    if (posTransaccion != -1)
                    {
                        caja->agregarTransaccion(trasacciones2[posTransaccion]);
                    }
                    
                }
                if (caja != nullptr)
                {
                    cajas.push_back(caja);
                    caja = nullptr;
                }

            }
        }
        archivoEntrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return cajas;
}

vector<Factura*> LoadData::recuperarFacturas(string archivo)
{
    vector<Factura*> facturas;

    ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        Factura* factura = nullptr;
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("id: ") != string::npos) {
                factura = new Factura();
                factura->setId(stoi(linea.substr(4)));
            }
            if (linea.find("nit: ") != string::npos) {
                factura = new Factura();
                factura->setNit(stoi(linea.substr(5)));
            }
            if (linea.find("nombre: ") != string::npos) {
                factura = new Factura();
                factura->setNombre((linea.substr(8)));
            }
            else if (linea.find("IdT: ") != string::npos) {
                int transaccionId = stoi(linea.substr(5));
                int posTrans = 0;
                if (buscarTransaccion1(transaccionId) >= 0)
                {
                    posTrans = buscarTransaccion1(transaccionId);
                    if (posTrans != -1)
                    {
                        factura->setTransaccion(trasacciones1[posTrans]);
                    }
                    

                }
                if (buscarTransaccion2(transaccionId) >= 0)
                {
                    posTrans = buscarTransaccion2(transaccionId);
                    if (posTrans != -1)
                    {
                        factura->setTransaccion(trasacciones2[posTrans]);
                    }
                    

                }
                
            }
            if (linea.empty()) {
                if (factura != nullptr)
                {
                    facturas.push_back(factura);
                    factura = nullptr;
                }

            }
        }
        archivoEntrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return facturas;
}

vector<Transaccion*> LoadData::recuperarTransacciones(string archivo)
{
    vector<Transaccion*> transacciones;

    ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        Transaccion* transaccion = nullptr;
        string linea;
        
        while (getline(archivoEntrada, linea)) {
            if (linea.find("id: ") != string::npos) {
                transaccion = new Transaccion();
                transaccion->setId(stoi(linea.substr(4)));
            }
            else if (linea.find("monto: ") != string::npos) {
                transaccion->setMonto(stof(linea.substr(7)));
            }
            else if (linea.find("fecha: ") != string::npos) {
                string fechaStr = linea.substr(7);
                Fecha fecha;
                fecha.convertirString(fechaStr);
                transaccion->setFecha(fecha);
            }
            else if (linea.find("clienteId: ") != string::npos) {
                int clienteId = (stoi(linea.substr(11)));

                int posCliente = buscarCliente(clienteId);
                if (posCliente != -1)
                {
                    transaccion->setCliente(clientes[posCliente]);
                }
                
            }
            else if (linea.find("empleadoId: ") != string::npos) {  
                int empleadoId = (stoi(linea.substr(12)));
                int posEmpleado = buscarEmpleado(empleadoId);
                if (posEmpleado != -1)
                {   
                    transaccion->setEmpleado(empleados[posEmpleado]);
                }
                
            }

            else if (linea == "Carrito:") {
                // Iniciar la lectura de los productos
                while (getline(archivoEntrada, linea) && !linea.empty()) {;
                    int productoId = stoi(linea);
                    int posProducto = buscarProducto(productoId);
                    if (posProducto != -1)
                    {
                        Carrito carrito;
                        carrito.agregarProducto(productos[posProducto]);
                        transaccion->agregarCarrito(carrito);
                    }
                }
            }
            if (linea.empty()) {
                if (transaccion != nullptr)
                {
                    transacciones.push_back(transaccion);
                    transaccion = nullptr;
                }

            }
        }
        archivoEntrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return transacciones;
}



int LoadData::buscarTransaccion1(int idTransaccion)
{
    int pos= -1;
    for (int i = 0; i < trasacciones1.size(); i++)
    {
        if (trasacciones1[i]->getId() == idTransaccion)
        {
            pos = i;
        }
    }
    return pos;
}

int LoadData::buscarTransaccion2(int idTransaccion)
{
    int pos = -1;
    for (int i = 0; i < trasacciones2.size(); i++)
    {
        if (trasacciones2[i]->getId() == idTransaccion)
        {
            pos = i;
        }
    }
    return pos;
}

int LoadData::buscarCliente(int idCliente)
{
    int pos=-1;
    for (int i = 0; i < clientes.size(); i++)
    {
        if (clientes[i]->getId() == idCliente)
        {
            pos = i;
        }
    }
    return pos;
}

int LoadData::buscarEmpleado(int idEmpleado)
{
    int pos= -1;
    for (int i = 0; i < empleados.size(); i++)
    {
        if (empleados[i]->getId() == idEmpleado)
        {
            pos = i;
        }
    }
    return pos;
}

int LoadData::buscarProducto(int idProducto)
{
    int pos = -1;
    for (int i = 0; i < productos.size(); i++)
    {
        if (productos[i]->getId() == idProducto)
        {
            pos = i;
        }
    }
    //cout << pos << endl;
    return pos;
}

int LoadData::buscarProveedor(int proveedor)
{
    int pos= -1;
    for (int i = 0; i < proveedores.size(); i++)
    {
        if (proveedores[i]->getId() == proveedor)
        {
            pos = i;
        }
    }
    return pos;
}

void LoadData::ComplementarProducto_Proveedor()
{
    //for (int i = 0; i < productos.size(); i++)
    //{

    //    cout<<productos[i]->getNombre() << endl;
    //    

    //}
    ////cout<<"proveedores" << endl;
    //for (int i = 0; i < proveedores.size(); i++)
    //{
    //    cout << proveedores[i]->getNombre() << endl;;

    //}
    int posProveedor= -1;
    for (int i = 0; i < productos.size(); i++)
    {
        posProveedor=buscarProveedor(productos[i]->getIdProveedor());
        if (posProveedor != -1)
        {
            productos[i]->añadirProveedor(proveedores[posProveedor]);
        }
        
    }
    int posProducto= -1;
    //cout << "nroProveedores" << proveedores.size()<<endl;
    for (int i = 0; i < proveedores.size(); i++)
    {
        for (int j = 0; j < proveedores[i]->getIdProductosLoadData().size();j++)
        {
            //cout << "id prod" << endl;
           // cout<<proveedores[i]->getIdProductosLoadData()[j]<<endl;
            posProducto = buscarProducto(proveedores[i]->getIdProductosLoadData()[j]);
            if (posProducto != -1)
            {
                proveedores[i]->añadirProducto(productos[posProducto]);
            }
            
        }
        //cout << "otro proveedor" << endl;
    }
    //cout << "funcion acabada" << endl;

}

void LoadData::ComplementarCliente_transaccion()
{
    for (int i = 0; i < clientes.size(); i++)
    {
        int posTransaccion = 0;
        int posTransaccion2 = 0;
        //cout << "nro di ventas : cli " << clientes[i]->getVentasId().size() << endl;
        if (clientes[i]->getVentasId().size() > 0)
        {
            for (int j = 0; j < clientes[i]->getVentasId().size(); j++)
            {

                posTransaccion = buscarTransaccion1(clientes[i]->getVentasId()[j]);
                posTransaccion2 = buscarTransaccion2(clientes[i]->getVentasId()[j]);
                //cout << "pos1 trans: "<<posTransaccion << endl;
                //cout << "pos1 trans: "<<posTransaccion2 << endl;
                if (posTransaccion != -1)
                {
                    clientes[i]->añadirTransacccion(trasacciones1[posTransaccion]);
                //    cout << "se añadio una transaccion 1" << endl;
                }
                if (posTransaccion2 != -1)
                {
                //    cout << "se añadio una transaccion 2" << endl;
                    clientes[i]->añadirTransacccion(trasacciones2[posTransaccion2]);
                    
                }
            }
        }

        
    }
    //cout << "completar transacciones" << endl;
}

vector<Producto*> LoadData::getProductos()
{
    return productos;
}

vector<Cliente*> LoadData::getClientes()
{
    return clientes;
}

vector<Empleado*> LoadData::getEmpleados()
{
    return empleados;
}

vector<Proveedor*> LoadData::getProveedor()
{
    return proveedores;
}

vector<CajaRegistradora*> LoadData::getCajas()
{
    return cajas;
}

vector<Factura*> LoadData::getFacturas()
{
    return facturas;
}



