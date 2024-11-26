#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;
//Codigo para implementar tablas hash con double hashing
// Una clase para un elemento de la tabla
template<class T>
class Element {
 public:
 string str_key; // Llave string, como "Ana" 
 int int_key ; // Llave entera, resultante de la llave string
 int h_key; // Indice real asignado con base en int_key
 T item; // El objeto asociado con la llave
 bool free; // Una bandera para saber si este elemento de la 
tabla esta libre o no
 // Constructor 
 Element<T> ()
 { str_key = "";
 int_key = -1;
 h_key = -1;
 item = -1;
 free = true; 
 }
};
// Una clase que sera la tabla hash
template<class T>
class Hash 
{ public:
 int maxSize; // tamaño maximo
 int currentSize; // tamaño actual
 Element<T> **table; // puntero a arreglo de los elementos
 //Constructor se inicializa la tabla con el tamaño dado
 Hash(int size)
 { int j;
 maxSize = size;
 currentSize = 0;
 // Sintaxis: 
 // var = new tipo_dato*[num_elems]
 table = new Element<T>*[maxSize];
 
 for(j = 0; j < maxSize; j++ )
 { table[j] = new Element<T>(); }
 }
 void show(); // ver toda la tabla
 void insert(string, T); // agregar un elemento nuevo, recibe 
key y value
 void remove(string); // revomer uno por su key
 int find(string); // encontrar el indice de una key
 void update(string, T); // Funcion para cambiar el valor entero (item 
asociado con una cierta llave) 
 int hash1(int key)
