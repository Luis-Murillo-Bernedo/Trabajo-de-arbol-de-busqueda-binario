#include <iostream>
using namespace std;
struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
};
typedef struct nodo *Arbol;
Arbol CrearNodo(int x)
{
	Arbol nuevo=new(struct nodo);
	nuevo->dato=x;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
}
int Adicionar(Arbol &raiz,int valor,int contador)
{
	Arbol aux;
	if(raiz==NULL)
	{
		aux=CrearNodo(valor);
		raiz=aux;
		return contador;
	}
	else
	{
		contador++;
		if(valor<raiz->dato)
			Adicionar(raiz->izq,valor,contador);
		else
			if(valor>raiz->dato)
				Adicionar(raiz->der,valor,contador);
	}
}
void mostrar(Arbol &hoja)
{
	if(hoja!=NULL)
	{
		mostrar(hoja->izq);
		cout<<hoja->dato<<endl;
		mostrar(hoja->der);
	}
}
int main()
{
	Arbol raiz=NULL;
	int A[12]={60,30,70,20,55,90,35,80,95,45,40,50},c=0,iteraciones;
	for(int i=0;i<12;i++)
		Adicionar(raiz,A[i],c);
	iteraciones=Adicionar(raiz,33,c);
	mostrar(raiz);
	cout<<"---------------------"<<endl<<"Numero de iteraciones al adicionar el ultimo nodo: "<<iteraciones;
}
