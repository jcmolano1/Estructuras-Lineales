#include "cancion.h"

Cancion::Cancion() {
	this->nombre = "";
	this->genero = "";
}

void Cancion::nombreCancion(std::string nombrecancion) {
	this->nombre = nombrecancion;
}

void Cancion::Genero(std::string generocancion) {
	this->genero = generocancion;
}

std::string Cancion::obtenerNombre() {
	return this->nombre;
}

std::string Cancion::obtenerGenero() {
	return this->genero;
}

void Cancion::imprimirCancion() {
 	std::cout << this->nombre << "|" << this->genero << std::endl;
}
