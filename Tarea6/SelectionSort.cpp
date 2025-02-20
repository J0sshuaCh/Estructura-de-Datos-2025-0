#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector
{
private:
    int* m_pVect;  // Puntero al arreglo
    int  m_nCount; // Número de elementos en uso
    int  m_nMax;   // Capacidad máxima del arreglo
    int  m_nDelta; // Incremento para redimensionar

    // Función para inicializar las variables
    void Init(int delta)
    {
        m_nCount = 0;
        m_nMax   = delta;
        m_nDelta = delta;
        m_pVect  = new int[m_nMax]; // Crear el arreglo dinámico
    }

    // Función para redimensionar el arreglo si se sobrepasa la capacidad
    void Resize()
    {
        m_nMax += m_nDelta;
        int* temp = new int[m_nMax];

        for (int i = 0; i < m_nCount; i++)
        {
            temp[i] = m_pVect[i];
        }
        delete[] m_pVect;
        m_pVect = temp;
    }

public:
    CVector(int delta = 10)
    {
        Init(delta);
    }

    // Método para insertar un elemento al final del vector
    void Insert(int elem)
    {
        if (m_nCount == m_nMax)
        {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    // Método para mostrar los elementos del vector
    void Display()
    {
        for (int i = 0; i < m_nCount; i++)
        {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
    }

    // Método para ordenar el vector usando el algoritmo Selection Sort
    void SelectionSort()
    {
        for (int i = 0; i < m_nCount - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < m_nCount; j++)
            {
                if (m_pVect[j] < m_pVect[minIndex])
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                int temp = m_pVect[i];
                m_pVect[i] = m_pVect[minIndex];
                m_pVect[minIndex] = temp;
            }
        }
    }

    ~CVector()
    {
        delete[] m_pVect;
    }
};

int main()
{
    CVector gVect;
    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);
    gVect.Insert(5);
    gVect.Insert(50);
    gVect.Insert(15);

    cout << "Antes de ordenar: ";
    gVect.Display();

    gVect.SelectionSort();

    cout << "Después de ordenar: ";
    gVect.Display();

    return 0;
}
