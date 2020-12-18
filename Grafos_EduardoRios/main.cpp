#include <iostream>//Librerías
#include <windows.h>
#include "Grafo.h"

using namespace std;

int main() {//Funcion main
	Grafo G;
	G.Inicializa();
	int opc;
	
	do //Sentencia do while
	{
		system("cls");//Menu
		cout<<"\t .:MENU:."<<endl;
		cout<<"1. Ingresar vertice"<<endl;
		cout<<"2. Ingresar arista"<<endl;
		cout<<"3. Lista de adyacencia"<<endl;
		cout<<"4. Tamanio "<<endl;
		cout<<"5. Eliminar vertice"<<endl;
		cout<<"6. Eliminar arista"<<endl;
		cout<<"7. Anular"<<endl;
		cout<<"8. Recorrido en anchura"<<endl;
		cout<<"9. Recorrido en profundidad"<<endl;
		cout<<"10.Salir"<<endl;
		cout<<"Digite la opcion que desea: ";
		cin>>opc;
		
		switch(opc){
			case 1://Ingresar vertice
			{
				string nombre;
				system("cls");
				cout<<"Ingrese el nombre del vertice :";
				cin.ignore();
				getline(cin, nombre,'\n');
				G.InsertaVertice(nombre);
				cin.get();
				cin.get();
				break;
			}
			case 2://Caso 2: ingresar arista
			{
				string origen, destino;
				int peso;
				system("cls");
				if(G.Vacio()){//Si el grafo esta vacio
					cout<<"El grafo esta vacio"<<endl;
				}else{
					cout<<"Ingrese el nombre del vertice origen: ";
					cin.ignore();
					getline(cin, origen, '\n');
					cout<<"Ingrese el nombre del vertice destino :";
					getline(cin, destino, '\n');
					cout<<"Ingrese el peso: ";
					cin>>peso;
					
					if(G.GetVertice(origen)==NULL || G.GetVertice(destino)==NULL){
						cout<<"Uno de los vertices no es valido"<<endl;
						
					}else{
						G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
					}
					
				}
				cin.get();
				cin.get();
				break;
			}
			case 3://Caso 3: Lista de adyacencia
				{
				system("cls");
				if(G.Vacio()){//Si el grafo esta vacio
					cout<<"El grafo esta vacio "<<endl;
				}else{
					G.ListaAdyacencia();
				}
				cin.get();
				cin.get();
				break;
				}
			case 4://Caso 4: Tamaño
			{
				system("cls");
				if(G.Vacio()){//Si el grafo esta vacio
					cout<<"El grafo esta vacio"<<endl;
					
				}else{
					cout <<"El tamanio del grafo es: "<<G.Tamano()<<endl;
				}
				cin.get();
				cin.get();
				break;
			}
			case 5://Caso 5: Eliminar vertice
			{
				string nombre;
				system("cls");
				if(G.Vacio()){//Si el grafo esta vacio
					cout<<"El grafo esta vacio"<<endl;
				}else{
					cout<<"Ingrese el nombre del vertice a eliminar: ";
					cin.ignore();
					getline(cin, nombre, '\n');
					if(G.GetVertice(nombre)==NULL){
						cout<<"Vertice invalido"<<endl;
					}else{
						G.EliminarVertice(G.GetVertice(nombre));
					}
				}
				cin.get();
				cin.get();
				break;
			}
			
			case 6://Caso 6:Eliminar arista
				{
					string origen, destino;
					system("cls");
					if(G.Vacio()){//Si el grafo esta vacio
						cout<<"El grafo esta vacio"<<endl;
					}else{
						cout<<"Ingrese el nombre del vertice origen: "<<endl;
						cin.ignore();
						getline(cin, origen, '\n');
						cout<<"Ingrese el nombre del vertice de destino: "<<endl;
						getline(cin, destino, '\n');
						if(G.GetVertice(origen)==NULL || G.GetVertice(destino)==NULL){
							cout<<"Vertices no validos"<<endl;
						}else{
							G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino));
						}
					}
					cin.get();
					cin.get();
					break;
				}
			
			case 7://Caso 7: anular grafo
				{
					system("cls");
					if(G.Vacio()){//Si el grafo esta vacio
						cout<<"El grafo esta vacio"<<endl;
					}else{
						G.Anular();
					}
					cin.get();
					cin.get();
					break;
				}
			
			case 8://Caso 8: Recorrido en anchura
				{
					string nombre;
					system("cls");
					if(G.Vacio()){//Si el grafo esta vacio
						cout<<"El grafo esta vacio"<<endl;
					}else{
						cout<<"Ingrese el nombre del vertice inicial: ";
						cin.ignore();
						getline(cin, nombre, '\n');
						if(G.GetVertice(nombre)==NULL){
							cout<<"Vertice invalido"<<endl;
						}else{
							cout<<"Recorrido en anchura -> ";
							G.RecorridoAnchura(G.GetVertice(nombre));
						}
					}
				}
				cin.get();
				cin.get();
				break;
			case 9://Caso 9: Recorrido en profundidad
				{
					string nombre;
					system("cls");
					if(G.Vacio()){//Si el grafo esta vacio
						cout<<"El grafo esta vacio"<<endl;
					}else{
						cout<<"Ingrese el nombre del vertice inicial: ";
						cin.ignore();
						getline(cin, nombre, '\n');
						if(G.GetVertice(nombre)==NULL){
							cout<<"Vertice invalido"<<endl;
						}else{
							cout<<"Recorrido en profundidad -> ";
							G.RecorridoProfundidad(G.GetVertice(nombre));
						}
					}
				}
				cin.get();
				cin.get();
				break;
		}
		
	}while(opc!=10);
}
