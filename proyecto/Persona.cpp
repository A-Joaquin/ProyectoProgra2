#include "Persona.h"

Persona::Persona()
{
}

Persona::Persona(int id, string nombre, int edad, string direccion, int telefono, string correoElectronico)
{
	this->id = id;
	this->nombre = nombre;
	this->edad = edad;
	this->direccion=direccion;
	this->telefono=telefono;
	this->correoElectronico = correoElectronico;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getDireccion()
{
	return direccion;
}

void Persona::setId(int id)
{
	this->id = id;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Persona::setEdad(int edad)
{
	this->edad = edad;
}

void Persona::setTelefono(int telefono)
{
	this->telefono = telefono;
}

void Persona::setDireccion(string direccion)
{
	this->direccion = direccion;
}

void Persona::setCorreoElectronico(string correo)
{
	this->correoElectronico = correo;
}

int Persona::getTelefono()
{
	return telefono;
}

string Persona::getCorreoElectronico()
{
	return correoElectronico;
}

int Persona::getId()
{
	return id;
}

int Persona::getEdad()
{
	return edad;
}

string Persona::getDatosCliente()
{
	return id+ " " + nombre + " ";
}
