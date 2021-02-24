#include "autor.h"

Autor::Autor() {
	this->nombre = "";
	this->albumes.clear();
}

void Autor::nombreAutor(std::string autor) {
	this->nombre = autor;
}

void Autor::listaAutor(std::list<Album> listaautor) {
	this->albumes = listaautor;
}

std::string Autor::obtenerNombre() {
	return this->nombre;
}

std::list<Album> Autor::obtenerLista() {
	return this->albumes;
}

bool Autor::agregarCancion(std::string nombrecancion, std::string genero, std::string album, std::string year) {
	bool s = false;
	std::list<Album>::iterator aiT;
	std::list<Album>::iterator piT = albumes.end();
	for (aiT = albumes.begin(); aiT != albumes.end(); aiT++) {
		if (aiT->obtenerNombre() == album) {
			piT = aiT;
		}
	}
	if (piT == albumes.end()) {
		for (aiT = albumes.begin(); aiT != albumes.end(); aiT++) {
			if (aiT->obtenerNombre() > album) {
				break;
			}
		}
		Album *nombrealbum = new Album;
		nombrealbum->nombreAlbum(album);
		nombrealbum->albumyear(year);
		nombrealbum->agregarCancion(nombrecancion,genero);
		if (aiT != albumes.end()) {
			albumes.insert(aiT, *nombrealbum);
		} else {
			albumes.push_back(*nombrealbum);
		}
		s = true;
	} else {
		s = piT->agregarCancion(nombrecancion,genero);
	}

	return s;
}
