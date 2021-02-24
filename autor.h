#ifndef __AUTOR_H__
#define __AUTOR_H__

#include <list>
#include <string>
#include "album.h"

class Autor {
	protected:
		std::string nombre;
		std::list<Album> albumes;
	public:
		Autor();
		void nombreAutor(std::string autor);
		void listaAutor(std::list<Album> listaautor);
		std::string obtenerNombre();
		std::list<Album> obtenerLista();
		bool agregarCancion(std::string nombrecancion, std::string genero, std::string album, std::string year);
};

#include "autor.hxx"

#endif
