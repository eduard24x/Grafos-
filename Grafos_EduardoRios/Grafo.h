#ifndef GRAFO_H//librerías
#define GRAFO_H
#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Arista;//Prototipo de la clase arista

class Vertice{
	Vertice*sig;
	Arista*ady;
	string nombre;
	friend class Grafo;
};

class Arista{//Clase arista
	Arista*sig;
	Vertice*ady;
	int peso;
	friend class Grafo;
};

class Grafo
{
	Vertice *h;
	public:
		void Inicializa();//Prototipos de las funciones
		bool Vacio();
		int Tamano();
		Vertice *GetVertice(string nombre);
		void InsertaArista(Vertice*origen, Vertice*destino, int peso);
		void InsertaVertice(string nombre);
		void ListaAdyacencia();
		void EliminarArista(Vertice*origen, Vertice*destino);
		void Anular();
		void EliminarVertice(Vertice *vert);
		void RecorridoAnchura(Vertice *origen);
		void RecorridoProfundidad(Vertice *origen);
		
};


#endif
