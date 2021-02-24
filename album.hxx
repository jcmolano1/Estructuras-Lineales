#include "album.h"

Album::Album() {
	this->nombre = "";
	this->year = "";
	this->canciones.clear();
}

void Album::nombreAlbum(std::string nombre) {
	this->nombre = nombre;
}

void Album::albumyear(std::string year) {
	this->year = year;
}

void Album::listaAlbum(std::list<Cancion> listacanciones) {
	this->canciones = listacanciones;
}

std::string Album::obtenerNombre() {
	return this->nombre;
}

std::string Album::obteneryear() {
	return this->year;
}

std::list<Cancion> Album::obtenerLista() {
	return this->canciones;
}

bool Album::agregarCancion(std::string nombrecancion, std::string genero) {
	std::list<Cancion>::iterator ciT;
	bool duplicada = false;
	for (ciT = canciones.begin(); ciT != canciones.end(); ciT++) {
		if (ciT->obtenerNombre() == nombrecancion) {
			duplicada = true;
		}
	}
	if (!duplicada) {
		for (ciT = canciones.begin(); ciT != canciones.end(); ciT++) {
			if (ciT->obtenerNombre() > nombrecancion) {
				break;
			}
		}
		Cancion *nombre_cancion = new Cancion;
		nombre_cancion->nombreCancion(nombrecancion);
		nombre_cancion->Genero(genero);
		if (ciT != canciones.end()) {
			canciones.insert(ciT, *nombre_cancion);
		} else {
			canciones.push_back(*nombre_cancion);
		}
	}
	return !duplicada;
}

void Album::listarCanciones() {
	std::cout << "Cantidad de canciones del album " << nombre << ": " << canciones.size() << std::endl;
	std::list<Cancion>::iterator ciT;
	for (ciT = canciones.begin(); ciT != canciones.end(); ciT++) {
		ciT->imprimirCancion();
	}
}

void Album::imprimirAlbum() {
	std::cout << this->nombre << "|" << this->year << std::endl;
}
