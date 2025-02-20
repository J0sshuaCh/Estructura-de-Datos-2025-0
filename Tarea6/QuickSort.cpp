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

    // Función para particionar el arreglo para QuickSort
    int Partition(int left, int right)
    {
        int pivot = m_pVect[right];
        int i = left - 1;

        for (int j = left; j < right; j++)
        {

            if (m_pVect[j] <= pivot)
            {
                i++;

                int temp = m_pVect[i];
                m_pVect[i] = m_pVect[j];
                m_pVect[j] = temp;
            }
        }

        int temp = m_pVect[i + 1];
        m_pVect[i + 1] = m_pVect[right];
        m_pVect[right] = temp;
        return i + 1;
    }

    // Método recursivo para realizar QuickSort
    void QuickSort(int left, int right)
    {
        if (left < right)
        {
            int pivotIndex = Partition(left, right);
            QuickSort(left, pivotIndex - 1);
            QuickSort(pivotIndex + 1, right);
        }
    }

public:
    // Constructor
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

    // Método público para ordenar el vector usando QuickSort
    void QuickSort()
    {
        QuickSort(0, m_nCount - 1);
    }


    ~CVector()
    {
        delete[] m_pVect;
    }
};

// Función principal
int main()
{
    CVector gVect;

    gVect.Insert(23);
    gVect.Insert(10);
    gVect.Insert(37);
    gVect.Insert(3);
    gVect.Insert(47);
    gVect.Insert(16);

    cout << "Antes de ordenar: ";
    gVect.Display();

    gVect.QuickSort();

    cout << "Después de ordenar: ";
    gVect.Display();

    return 0;
}
