#pragma once

#include <string>
#include <iostream>

using namespace std;
class Persona
{
protected:
	int id;
	string nombre;
	int edad;
	string direccion;
	int telefono;
	string correoElectronico;

public:
	Persona();
	Persona(int id, string nombre, int edad,string direccion,int telefono, string correoElectronico);
	string getNombre();
	string getDireccion();
	void setId(int id);
	void setNombre(string nombre);
	void setEdad(int edad);
	void setTelefono(int telefono);
	void setDireccion(string direccion);
	void setCorreoElectronico(string correo);
	int getTelefono();
	string getCorreoElectronico();
	int getId();
	int getEdad();
	string getDatosCliente();

};

