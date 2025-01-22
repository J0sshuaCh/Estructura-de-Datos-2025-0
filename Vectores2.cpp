#include <iostream>
using namespace std;

/*
  Integrantes del grupo
  - Cansaya Cutipa Frank Manuel
  - Chavez Cerna Joshua Nicolas
 */

int *gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0; // Counter to know the number of used elements int
int gnMax = 0; // Variable containing the size of the allocated

void Resize()
{
  const int delta = 5; // Used to increase the vector size
  int *pTemp, i;
  pTemp = new int[gnMax + delta]; // Alloc a new vector
  for(i = 0 ; i < gnMax ; i++) // Transfer the elements
    pTemp[i] = gpVect[i]; // we can also use the function memcpy
  delete [ ] gpVect; // delete the old vector
  gpVect = pTemp; // Update the pointer
  gnMax += delta; // The Max has to be increased by delta
}

void Insert(int elem)
{
  if( gnCount == gnMax ) // There is no space at this moment for elem
    Resize(); // Resize the vector before inserting elem
  gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}

void Display()
{
  cout << "Elementos en el arreglo: ";
  for (int i = 0; i < gnCount; i++)
  {
    cout << gpVect[i] << " ";
  }
  cout << endl;
  cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}

void Eliminar(int elem) {
  int index = -1;

  for (int i = 0; i < gnCount; i++) {
    if (gpVect[i] == elem) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "Elemento " << elem << " no fue encontrado." << endl;
    return;
  }

  for (int i = index; i < gnCount - 1; i++) {
    gpVect[i] = gpVect[i + 1];
  }

  gnCount--;

  cout << "Elemento " << elem << " fue eliminado." << endl;
}

int main() {
  Insert(10);  // Insert element 10
  Insert(20);  // Insert element 20
  Insert(30);  // Insert element 30
  Insert(40);  // Insert element 40
  Insert(50);  // Insert element 50

  Display();  // Display the elements in the array

  Eliminar(20);

  Display();  // Display the updated array

  return 0;
}

/****************
Tarea 1 es borrar

gVect : 10, 20, 30

Delete(20)
Se supone que primero deben buscar el elemento Search()

gVect : 10, 30

*****************/