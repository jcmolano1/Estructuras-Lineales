#include <iostream>
#include "autor.h"
#include "cancion.h"
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
std::list<Autor> autores;

//clang++ -std=c++11 -stdlib=libc++ main.cpp -o main


bool agregarCanciones(std::string nombrecancion,std::string autorcancion,std::string genero,std::string album,std::string year)
{
  bool guardar=false;
  std::list<Autor>::iterator aiT;
  std::list<Autor>::iterator piT=autores.end();
  for (aiT=autores.begin();aiT!=autores.end();aiT++)
  {
    if (aiT->obtenerNombre()==autorcancion)
    {
      piT=aiT;
    }
  }
  if (piT==autores.end())
  {
    for (aiT=autores.begin();aiT!=autores.end();aiT++)
    {
      if (aiT->obtenerNombre()>autorcancion)
      {
        break;
      }
    }
    Autor *nuevoAutor = new Autor;
    nuevoAutor->nombreAutor(autorcancion);
    nuevoAutor->agregarCancion(nombrecancion,genero,year,album);
    if (aiT!=autores.end())
    {
      autores.insert(aiT,*nuevoAutor);
    }
    else
    {
      autores.push_back(*nuevoAutor);
    }
    guardar=true;
  }
  if (piT!=autores.end())
  {
    guardar=piT->agregarCancion(nombrecancion,genero,album,year);
  }
  return guardar;
}
bool lectura_archivo(std::string archivo)
{
  std::ifstream myfile (archivo);
  std::string line;
  std::string palabra;
       if (myfile.is_open()) {
         while ( getline (myfile,line) )
         {
           std::getline(myfile,line);
           std::cout<<line<<std::endl;
           std::vector<std::string>linea;
           linea.clear();
           std::stringstream data (line);
           while (getline(data,palabra,'|'))
           {
             linea.push_back(palabra);
           }
           agregarCanciones(linea[0],linea[1],linea[2],linea[3],linea[4]);
         }
         myfile.close();
       }
       else
       {
         std::cout<<"Unable to open file";
       }
       return 0;
}
void ListaAutores()
{
  std::list<Autor>::iterator aiT;
  for (aiT=autores.begin();aiT!=autores.end();aiT++)
  {
    std::cout<<aiT->obtenerNombre()<<std::endl;
  }
}
void cancionesAutor(std::string nomautor)
{
  std::list<Cancion> cancionesAutor;
	cancionesAutor.clear();
	std::list<Cancion>::iterator ciT;
	std::list<Autor>::iterator aiT;
	std::list<Autor>::iterator piT = autores.end();

	for (aiT = autores.begin(); aiT != autores.end(); aiT++) {
		if (aiT->obtenerNombre() == nomautor) {
			piT = aiT;
		}
	}

	if (piT != autores.end()) {

		std::list<Album> albumes = piT->obtenerLista();
		std::list<Album>::iterator aiTlb;
		std::list<Cancion> cancionxalbum;
		std::list<Cancion>::iterator caiT;

		for (aiTlb = albumes.begin(); aiTlb != albumes.end(); aiTlb++) {
			cancionxalbum = aiTlb->obtenerLista();

			for (caiT = cancionxalbum.begin(); caiT != cancionxalbum.end(); caiT++) {

				for (ciT = cancionesAutor.begin(); ciT != cancionesAutor.end(); ciT++) {
					if (ciT->obtenerNombre() > caiT->obtenerNombre()) {
						break;
					}
				}
				if (ciT != cancionesAutor.end()) {
					cancionesAutor.insert(ciT, *caiT);
				} else {
					cancionesAutor.push_back(*caiT);
				}

			}
		}

		std::cout << "Numero canciones del autor " << nomautor << ": " << cancionesAutor.size() << std::endl;
		for (ciT = cancionesAutor.begin(); ciT != cancionesAutor.end(); ciT++) {
			ciT->imprimirCancion();
		}
	} else {
		std::cout << "El autor " << nomautor << " no se encuentra en la base de datos" << std::endl;
	}
}

void ListaAlbum()
{
  std::list<Autor>::iterator aiT;
	std::list<Album> album, albumAutor;
	album.clear();
	std::list<Album>::iterator aliT, riT;

	for (aiT = autores.begin(); aiT != autores.end(); aiT++) {
		albumAutor = aiT->obtenerLista();

		for (aliT = albumAutor.begin(); aliT != albumAutor.end(); aliT++) {

			for (riT = album.begin(); riT != album.end(); riT++) {
				if (riT->obteneryear() > aliT->obteneryear()) {
					break;
				}
			}
			if (riT != album.end()) {
				album.insert(riT, *aliT);
			} else {
				album.push_back(*aliT);
			}

		}
	}

	std::cout << "Numero albumes: " << album.size() << std::endl;
	for (aliT = album.begin(); aliT != album.end(); aliT++) {
		aliT->imprimirAlbum();
	}
}


int main ( ) {

  std::string archivo;
  std::cout << "Ingrese nombre del archivo: ";
  std::cin >> archivo;
  lectura_archivo(archivo);
  std::string nomautor;
  std::string nomalbum;
  int x=20;
  while (x!=0)
  {
    std::cout<<"Opciones"<<std::endl;
    std::cout<<"1. Listar todos los autores presentes, ordenados alfabéticamente"<<std::endl;
    std::cout<<"2. Dado un autor, listar todas sus canciones ordenadas alfabéticamente"<<std::endl;
    std::cout<<"3. Listar todos los albumes presentes, ordenados cronológicamente."<<std::endl;
    std::cout<<"4. Dado un álbum, listar todas las canciones que componen un álbum, ordenadas alfabéticamente por el nombre de la canción"<<std::endl;
    std::cout<<"5. Listar todas las canciones y su álbum, ordenadas alfabéticamente primero por el álbum y después por el nombre de la canción."<<std::endl;
    std::cout<<"0. Salir"<<std::endl;
    std::cin>>x;
    std::cout<<std::endl;
    switch (x)
    {
      case 1:
        ListaAutores();
        break;
      case 2:
        std::cout << "Ingrese nombre autor: ";
        std::cin >>nomautor;
        cancionesAutor(nomautor);
        break;
      case 3:
        ListaAlbum();
        break;
      default:
        std::cout<<"Opcion no valida ";
        break;
    }
  }






  //ListaAutores();

  //cancionesAutor(nomautor);


	std::cout << std::endl;

  //ListaAlbum();

  //std::cout << "Ingrese nombre album: ";
  //std::cin >>nomalbum;


	return 0;
}