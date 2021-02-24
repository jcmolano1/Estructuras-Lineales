#ifndef __CANCION_H__
#define __CANCION_H__

#include <iostream>
#include <string>

class Cancion {
	protected:
	    std::string nombre;
	    std::string genero;
	public:
		Cancion();
		void nombreCancion(std::string nombrecancion);
		void Genero(std::string generocancion);
		std::string obtenerNombre();
		std::string obtenerGenero();
		void imprimirCancion();
};

#include "cancion.hxx"

#endif
