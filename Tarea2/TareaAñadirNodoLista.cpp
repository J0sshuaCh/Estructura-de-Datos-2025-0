#include <iostream>
using namespace std;

template <typename T>
class CLinkedList {
private:
    struct NODE {
        T m_data;
        NODE* m_pNext;
    };

    NODE* m_pRoot;

public:
    CLinkedList() : m_pRoot(nullptr) {}

    void Insert(T data) {
        NODE* newNode = new NODE{data, nullptr};

        if (m_pRoot == nullptr) {
            m_pRoot = newNode;
        } else {
            NODE* current = m_pRoot;
            while (current->m_pNext != nullptr) {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
        }
    }

    void InsertarAlInicio(T data) {
        NODE* newNode = new NODE{data, m_pRoot};
        m_pRoot = newNode;
    }

    void Print() const {
        NODE* current = m_pRoot;
        while (current != nullptr) {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }

    void Delete(T data) {
        if (m_pRoot == nullptr)
            return;

        if (m_pRoot->m_data == data) {
            NODE* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
            return;
        }

        NODE* current = m_pRoot;
        while (current->m_pNext != nullptr && current->m_pNext->m_data != data) {
            current = current->m_pNext;
        }

        if (current->m_pNext != nullptr) {
            NODE* temp = current->m_pNext;
            current->m_pNext = current->m_pNext->m_pNext;
            delete temp;
        } else {
            cout << "Value " << data << " not found in the list!" << endl;
        }
    }
};

// **Función principal**
int main() {
    CLinkedList<int> list;

    // Insertamos elementos al final
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    
    cout << "Lista original: ";
    list.Print();

    // Insertamos un nodo al inicio
    cout << "Insertando 5 al inicio" << endl;
    list.InsertarAlInicio(5);
    list.Print();

    cout << "Eliminando 20 de la lista" << endl;
    list.Delete(20);
    list.Print();

    return 0;
}