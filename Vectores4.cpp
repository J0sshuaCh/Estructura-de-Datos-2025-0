#include <iostream>
using namespace std;
/*
  Integrantes del grupo
  - Cansaya Cutipa Frank Manuel
  - Chavez Cerna Joshua Nicolas
 */
#include <iostream>
using namespace std;

class CVector {
private:
    int *m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    // Inicializa las variables internas
    void Init(int delta) {
        m_nDelta = delta;
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new int[m_nMax];
    }

    // Incrementa el tamaño del buffer si es necesario
    void Resize() {
        m_nMax += m_nDelta;
        int *pNewVect = new int[m_nMax];

        for (int i = 0; i < m_nCount; i++) {
            pNewVect[i] = m_pVect[i];
        }

        delete[] m_pVect;
        m_pVect = pNewVect;
    }

public:
    // Constructor con delta opcional
    CVector(int delta = 10) {
        Init(delta);
    }

    // Destructor para liberar memoria
    ~CVector() {
        delete[] m_pVect;
    }

    // Inserta un elemento al final del vector
    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    // Muestra los elementos actuales del vector
    void Display() {
        cout << "Elementos en el vector: ";
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
        cout << "Cantidad de elementos almacenados: " << m_nCount << endl;
    }
};

int main() {
    CVector gVect;

    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);

    gVect.Display();

    return 0;
}

