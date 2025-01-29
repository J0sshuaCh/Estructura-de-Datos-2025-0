#include <iostream>
using namespace std;
/*
  Integrantes del grupo
  - Cansaya Cutipa Frank Manuel
  - Chavez Cerna Joshua Nicolas
 */
int gVect[100];
int gnCount = 0;

// Inserta un elemento al final del arreglo
void Insert(int elem)
{
  if (gnCount < 100)
    gVect[gnCount++] = elem;
}

// Busca un elemento y retorna su índice, o -1 si no se encuentra
int Search(int elem)
{
  for (int i = 0; i < gnCount; i++)
  {
    if (gVect[i] == elem)
      return i;
  }
  return -1;
}

// Elimina un elemento moviendo los elementos restantes
void Delete(int elem)
{
  int index = Search(elem);
  if (index == -1)
  {
    cout << "Elemento no encontrado: " << elem << endl;
    return;
  }

  for (int i = index; i < gnCount - 1; i++)
  {
    gVect[i] = gVect[i + 1];
  }
  gnCount--;
  cout << "Elemento eliminado: " << elem << endl;
}


void Display()
{
  cout << "Elementos en el arreglo: ";
  for (int i = 0; i < gnCount; i++)
  {
    cout << gVect[i] << " ";
  }
  cout << endl;
  cout << "Cantidad de elementos almacenados: " << gnCount << endl;
}

int main(int argc, char *argv[])
{
  Insert(20);
  Insert(10);
  Insert(30);

  Display();

  Delete(20);

  Display();
  return 0;
}
