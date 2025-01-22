#include <iostream>
using namespace std;

/*
  Integrantes del grupo
  - Cansaya Cutipa Frank Manuel
  - Chavez Cerna Joshua Nicolas
 */

struct Vector
{
  int*m_pVect, // Pointer to the buffer
    m_nCount, // Control how many elements are actually used
    m_nMax, // Control how many are allocated as maximum
    m_nDelta; // To control the growing
};

void Resize(Vector *pThis)
{

  const int delta = 5; // Used to increase the vector size
  int *pTemp, i;
  pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Alloc a new vector
  for(i = 0 ; i < pThis->m_nMax ; i++) // Transfer the elements
    pTemp[i] = pThis->m_pVect[i]; // we can also use the function memcpy
  delete [ ] pThis->m_pVect; // delete the old vector
  pThis->m_pVect = pTemp; // Update the pointer
  pThis->m_nMax += pThis->m_nDelta; // The Max has to be increased by delta
}
void Insert(Vector *pThis, int elem)
{
  if( pThis->m_nCount == pThis->m_nMax )
    Resize(pThis);

  pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Display(Vector *pThis)
{
  cout << "Elementos en el arreglo: ";
  for (int i = 0; i < pThis->m_nCount; i++)
  {
    cout << pThis->m_pVect[i] << " ";
  }
  cout << endl;
  cout << "Cantidad de elementos almacenados:" << pThis->m_nCount <<endl;
}

void Eliminar(Vector *pThis, int elem) {
  int index = -1;
  for (int i = 0; i < pThis->m_nCount; i++) {
    if (pThis->m_pVect[i] == elem) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    cout << "Elemento " << elem << " no fue encontrado en el arreglo." << endl;
    return;
  }
  for (int i = index; i < pThis->m_nCount - 1; i++) {
    pThis->m_pVect[i] = pThis->m_pVect[i + 1];
  }
  pThis->m_nCount--;
  cout << "Elemento " << elem << " fue eliminado del arreglo." << endl;
}

int main(int argc, char *argv[]) {
  Vector myVect;
  myVect.m_nCount = 0;
  myVect.m_nMax = 0;
  myVect.m_nDelta = 5;

  Insert(&myVect, 10);  // Insert element 10
  Insert(&myVect, 20);  // Insert element 20
  Insert(&myVect, 30);  // Insert element 30

  Display(&myVect);  // Display the elements in the array

  Eliminar(&myVect, 20);

  Display(&myVect);
  return 0;
}


