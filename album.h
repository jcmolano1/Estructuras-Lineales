#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <list>
#include <string>
#include "cancion.h"

class Album {
	protected:
		std::string nombre;
		std::string year;
		std::list<Cancion> canciones;
	public:
		Album();
		void nombreAlbum(std::string nombre);
		void albumyear(std::string year);
		void listaAlbum(std::list<Cancion> canciones);
		std::string obtenerNombre();
		std::string obteneryear();
		std::list<Cancion> obtenerLista();
		bool agregarCancion(std::string nombrecancion, std::string genero);
		void listarCanciones();
		void imprimirAlbum();
};

#include "album.hxx"

#endif
