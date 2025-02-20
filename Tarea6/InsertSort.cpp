#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector {
private:
    int* m_pVect;  // Puntero al arreglo
    int  m_nCount; // Número de elementos en uso
    int  m_nMax;   // Capacidad máxima del arreglo
    int  m_nDelta; // Incremento para redimensionar

    // Función para inicializar las variables
    void Init(int delta) {
        m_nCount = 0;
        m_nMax   = delta;
        m_nDelta = delta;
        m_pVect  = new int[m_nMax]; // Crear el arreglo dinámico
    }

    // Función para redimensionar el arreglo si se sobrepasa la capacidad
    void Resize() {
        m_nMax += m_nDelta; // Aumentar el tamaño máximo
        int* temp = new int[m_nMax]; // Crear un nuevo arreglo más grande
        for (int i = 0; i < m_nCount; i++) {
            temp[i] = m_pVect[i]; // Copiar los elementos al nuevo arreglo
        }
        delete[] m_pVect;   // Liberar la memoria del arreglo anterior
        m_pVect = temp;     // Apuntar al nuevo arreglo
    }

public:
    // Constructor
    CVector(int delta = 10) {
        Init(delta);
    }

    // Método para insertar un elemento al final del vector
    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    // Método para mostrar los elementos del vector
    void Display() {
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
    }

    // Método para ordenar el vector usando el algoritmo Insertion Sort
    void InsertionSort() {

        for (int i = 1; i < m_nCount; i++) {
            int key = m_pVect[i];
            int j = i - 1;

            while (j >= 0 && m_pVect[j] > key) {
                m_pVect[j + 1] = m_pVect[j];
                j--;
            }
            m_pVect[j + 1] = key;
        }
    }


    ~CVector() {
        delete[] m_pVect;
    }
};

// Función principal
int main() {
    CVector gVect;

    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);
    gVect.Insert(5);
    gVect.Insert(50);
    gVect.Insert(15);

    cout << "Antes de ordenar: ";
    gVect.Display();

    gVect.InsertionSort();

    cout << "Después de ordenar: ";
    gVect.Display();

    return 0;
}
