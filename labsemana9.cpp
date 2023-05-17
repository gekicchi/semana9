#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

// ejercicio 1
class Rectangle
{
private:
	float _Ancho;
	float _Largo;
	
public:
	Rectangle() // constructor default
	{
		_Ancho = 1;
		_Largo = 1;
		cout << "Rectangulo Default Creado" << endl;
	}
	Rectangle(float ancho, float largo) // constructor con parametros
	{
		_Ancho = ancho;
		_Largo = largo;
		cout << "Rectangulo Creado" << endl;
	}
	~Rectangle() // destructor
	{
		delete[] &_Ancho;
		delete[] &_Largo;
	}
	
	// get-sets
	void setAncho(float ancho)
	{
		_Ancho = ancho;
	}
	float getAncho()
	{
		return _Ancho;
	}
	void setLargo(float largo)
	{
		_Largo = largo;
	}
	float getLargo()
	{
		return _Largo;
	}
	
	float CalcularArea() // metodo de calculo de area
	{
		return _Ancho * _Largo;
	}
};

// ejercicio 2
class Point
{
private:
	float _EjeX;
	float _EjeY;
	
public:
	Point() // constructor default
	{
		_EjeX = 0;
		_EjeY = 0;
	}
	Point(float x, float y) // constructor con parametros
	{
		_EjeX = x;
		_EjeY = y;
	}
	~Point() // destructor
	{
		delete[] &_EjeX;
		delete[] &_EjeY;
	}
	
	void setEjeX(float x)
	{
		_EjeX = x;
	}
	float getEjeX()
	{
		return _EjeX;
	}
	
	void setEjeY(float y)
	{
		_EjeY = y;
	}
	float getEjeY()
	{
		return _EjeY;
	}
	
	void MoverPunto(float movX, float movY)
	{
		cout << "Coordenadas Originales: " << _EjeX << "," << _EjeY << endl;
		_EjeX += movX;
		_EjeY += movY;
		cout << "Coordenadas Nuevas: " << _EjeX << "," << _EjeY << endl;
	}
};

// ejercicio 4
struct NodeList
{
	int data;
	NodeList* next;
};

class LinkedList
{
private:
	NodeList* head;
	
public:
	LinkedList()
	{
		head = NULL;
	}
	LinkedList(NodeList* inicio)
	{
		head = inicio;
	}
	~LinkedList()
	{
		delete[] head;
	}
	
	void setHead(NodeList* inicio)
	{
		head = inicio;
	}
	NodeList* getHead()
	{
		return head;
	}
	
	void Insertar(NodeList* nuevoNodo)
	{
		if (head == NULL)
		{
			head = nuevoNodo;
		}
		else
		{
			NodeList* current = head;
			while (current->next != NULL)
				current = current->next;
				
			current->next = nuevoNodo;
		}
	}
	
	bool Buscar(int dat)
	{
		if (head == NULL)
		{
			cout << "Lista Vacia" << endl;
			return false;
		}
		
		NodeList* current = head;
		while (current != NULL)
		{
			if (current->data == dat)
				return true;
			current = current->next;
		}
		return false;
	}
	
	NodeList* Eliminar(int dat)
	{
		if (head == NULL)
		{
			cout << "Lista Vacia" << endl;
			return NULL;
		}
		if (Buscar(dat))
		{
			NodeList* current = head;
			NodeList* prev = head;
			
			while (current != NULL)
			{
				if (current->data == dat)
					break;
				
				prev = current;
				current = current->next;
			}
			
			if (current != NULL)
			{
				if (current == prev && current->next == NULL) // unico elemento en lista
					head = NULL;
				else if (current == prev) // primer elemento en lista
					head = head->next;
				else if (current != prev && current->next == NULL) // ultimo elemento en lista
					prev->next = NULL;
				else // elemento en medio de lista
					prev->next = current->next;
				
				current->next = NULL;
				
				return current;
			}
		}
		return NULL;
	}
	
	void Imprimir()
	{
		if (head == NULL)
		{
			cout << "Lista Vacia" << endl;
			return;
		}
		
		NodeList* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	
};


// ejercicio 5
struct NodeTree
{
	int data;
	NodeTree* left;
	NodeTree* right;
};

class BinaryTree
{
private:
	NodeTree* root;
	
public:
	BinaryTree()
	{
		root = NULL;
	}
	BinaryTree(NodeTree* inicio)
	{
		root = inicio;
	}
	~BinaryTree()
	{
		delete[] root;
	}
	
	void setRoot(NodeTree* inicio)
	{
		root = inicio;
	}
	NodeTree* getRoot()
	{
		return root;
	}
	
	NodeTree* Insertar(NodeTree* nuevoNodo, NodeTree* current)
	{
		if (current == NULL)
		{
			current = nuevoNodo;
		}
		else
		{
			if (nuevoNodo->data <= current->data)
				current->left = Insertar(nuevoNodo, current->left);
			else
				current->right = Insertar(nuevoNodo, current->right);
		}
		return current;
	}
	
	bool Buscar(int dat, NodeTree* current)
	{
		if (current == NULL)
		{
			return false;
		}
		else
		{
			if (current->data == dat)
				return true;
			
			if (dat < current->data)
				return Buscar(dat, current->left);
			else
				return Buscar(dat, current->right);
		}
	}
	
	void Imprimir(NodeTree* current)
	{
		if (current == NULL)
			return;
		
		Imprimir(current->left);
		cout << current->data << " ";
		Imprimir(current->right);
	}
};



int main()
{
	cout << "Prueba ejercicio 1" << endl;
	
	Rectangle rectDefault = Rectangle();
	Rectangle rectParams = Rectangle(2.78, 3.14);
	
	cout << "Area rectangulo default: " << rectDefault.CalcularArea() << endl;
	cout << "Area rectangulo por parametros: " << rectParams.CalcularArea() << endl;
	
	cout << endl << "Prueba ejercicio 2" << endl;
	
	Point puntoDefault = Point();
	Point puntoParams = Point(2, 5);
	
	puntoDefault.MoverPunto(2, -2);
	puntoParams.MoverPunto(-1, 4);
	
	cout << endl << "Prueba ejercicio 4" << endl;
	srand((unsigned) time(NULL));
	LinkedList listaNodos = LinkedList();
	for (int i=0; i < 5; i++)
	{
		NodeList* nodo = new NodeList;
		nodo->data = rand()%10;
		nodo->next = NULL;
		
		listaNodos.Insertar(nodo);
	}
	
	listaNodos.Imprimir();
	
	for (int i=0; i < 5; i++)
	{
		int buscando = rand()%10;
		cout << "Buscando " << buscando << "..." << endl;
		if (listaNodos.Buscar(buscando))
		{
			cout << "Nodo Encontrado!" << endl;
		}
		else
		{
			cout << "Nodo no Existe en Lista" << endl;
		}
	}
	
	for (int i=0; i < 3; i++)
	{
		int eliminando = rand()%10;
		cout << "Eliminando " << eliminando << "..." << endl;
		NodeList* eliminado = listaNodos.Eliminar(eliminando);
		if (eliminado != NULL)
			cout << "Nodo Eliminado: " << eliminado->data;
	}
	
	listaNodos.Imprimir();
	
	return 0;
}
