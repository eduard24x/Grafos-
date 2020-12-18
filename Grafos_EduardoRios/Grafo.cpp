#include "Grafo.h"

void Grafo:: Inicializa(){//Funcion inicializa
	h=NULL;
}

bool Grafo :: Vacio(){//Funcion vacio sirve para comprobar si el grafo tiene elementos
	if(h==NULL){
		return true;
	}else{
		return false;
	}
}

int Grafo::Tamano(){//método tamaño
	int cont=0;
	Vertice*aux;
	aux=h;
	while(aux!= NULL){
		cont++;
		aux=aux->sig;
	}
	return cont;
}

Vertice*Grafo::GetVertice(string nombre){//Método para obtener vertice
	Vertice*aux;
	aux=h;
	while (aux!=NULL){
		if(aux->nombre==nombre){
			return aux;
		}
		aux=aux->sig;
	}
	return NULL;
} 

void Grafo::InsertaVertice(string nombre){//Método insertaVertice
	Vertice*nuevo=new Vertice;
	nuevo->nombre=nombre;
	nuevo->sig=NULL;
	nuevo->ady=NULL;
	
	if(Vacio()){
		h=nuevo;
	}else{
		Vertice*aux;
		aux=h;
		while(aux->sig !=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
	}
}

void Grafo::InsertaArista(Vertice*origen, Vertice*destino, int peso){//Método para insertar una arista
	Arista*nueva=new Arista;
	nueva->peso=peso;
	nueva->sig=NULL;
	nueva->ady=NULL;
	
	Arista*aux;
	
	aux=origen->ady;
	
	if(aux==NULL){//Si el origen no tiene arista
		origen ->ady=nueva;
		nueva->ady=destino;
	}else{
		while(aux->sig !=NULL){
			aux=aux->sig;
		}
		aux->sig=nueva;
		nueva->ady=destino;
	}
}

void Grafo::ListaAdyacencia(){//Función para imprimir la lista de adyacencia
	Vertice*VertAux;
	Arista*ArisAux;
	
	VertAux=h;
	while(VertAux!=NULL){
		cout <<VertAux->nombre<<"->";
		ArisAux=VertAux->ady;
		while(ArisAux !=NULL){
			cout<<ArisAux->ady->nombre<<"->";
			ArisAux=ArisAux->sig;
		}
		VertAux=VertAux->sig;
		cout<<endl;
	}
}

void Grafo::Anular(){//Función anular
	Vertice*aux;
	
	while(h !=NULL){
		aux=h;
		h=h->sig;
		delete(aux);
	}
}

void Grafo::EliminarArista(Vertice*origen, Vertice*destino){//Función eliminarArista
	int band=0;
	Arista*actual, *anterior;
	actual=origen->ady;
	
	if(actual==NULL){
		cout<<"El vertice origen no tiene aristas"<<endl;
		
	}else if(actual->ady==destino){
		origen->ady=actual->sig;
		delete(actual);
	}else{
		while(actual !=NULL){
			if(actual->ady==destino){
				band=1;
				anterior->sig=actual->sig;
				delete(actual);
				break;
			}
			anterior=actual;
			actual=actual->sig;
		}
		if(band==0){
			cout <<"Esos dos vertices no están conectados"<<endl;
		}
	}
}

void Grafo::EliminarVertice(Vertice *vert){//funcion para eliminar vertice
	Vertice *actual, *anterior;
	Arista *aux;
	
	actual=h;
	while(actual!=NULL){
		aux=actual->ady;
		while(aux!=NULL){
			if(aux->ady==vert){
				EliminarArista(actual, aux->ady);
				break;
			}	
			aux=aux->sig;
		}
		actual=actual->sig;
	}
	actual=h;
	if(h==vert){
		h=h->sig;
		delete(actual);
	}else{
		while(actual!=vert){
			anterior=actual;
			actual=actual->sig;
		}
		anterior->sig=actual->sig;
		delete(actual);
	}
}

void Grafo::RecorridoAnchura(Vertice *origen){//Función para realizar el recorrido en anchura
	int band, band2;
	Vertice *actual;
	queue<Vertice*> cola;
	list<Vertice*> lista;
	list<Vertice*>::iterator i;
	
	cola.push(origen);
	
	while(!cola.empty()){
		band=0;
		actual=cola.front();
		cola.pop();
		
		for(i=lista.begin(); i!=lista.end(); i++){
			if(*i==actual){
				band=1;
			}
		}
		if(band==0){
			cout<<actual->nombre<<", ";
			lista.push_back(actual);
			
			Arista *aux;
			aux=actual->ady;
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin(); i!=lista.end(); i++){
					if(aux->ady==*i){
						band2=1;
					}
				}
				if(band2==0){
					cola.push(aux->ady);
				}
				aux=aux->sig;
			}
		}
	}
}

void Grafo::RecorridoProfundidad(Vertice *origen){//Función para realizar el recorrido en profundidad
	
	int band, band2;
	Vertice *actual;
	stack<Vertice*>pila;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	
	pila.push(origen);
	
	while(!pila.empty()){
		band=0;
		actual=pila.top();
		pila.pop();
		
		for(i=lista.begin(); i!=lista.end(); i++){
			if(*i==actual){
				band=1;
			}
		}
		if(band==0){
			cout<<actual->nombre<<", ";
			lista.push_back(actual);
			
			Arista *aux;
			aux=actual->ady;
			
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin(); i!=lista.end(); i++){
					if(*i==aux->ady){
						band2=1;
					}
				}
				if(band2==0){
					pila.push(aux->ady);
				}
				aux=aux->sig;
			}
		}
	}
}



