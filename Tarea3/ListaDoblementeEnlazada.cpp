#include <iostream>
using namespace std;

template <typename T>
class CDoublyLinkedList
{
private:
    struct NODE
    {
        T m_data;
        NODE* m_pNext;
        NODE* m_pPrev;
    };

    NODE* m_pRoot;
    NODE* m_pTail;

public:
    CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}

    void Insert(const T& data)
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;
        newNode->m_pPrev = nullptr;

        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
            m_pTail = newNode;
        }
        else
        {
            m_pTail->m_pNext = newNode;
            newNode->m_pPrev = m_pTail;
            m_pTail = newNode;
        }
    }

    void Print() const
    {
        NODE* current = m_pRoot;
        while (current != nullptr)
        {
            cout << current->m_data << " <-> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }

    void Delete(const T& data)
    {
        if (m_pRoot == nullptr)
            return;

        NODE* current = m_pRoot;

        while (current != nullptr && current->m_data != data)
        {
            current = current->m_pNext;
        }


        if (current == nullptr)
        {
            cout << "El valor " << data << " no está en la lista!" << endl;
            return;
        }

        if (current == m_pRoot)
        {
            m_pRoot = current->m_pNext;
            if (m_pRoot)
                m_pRoot->m_pPrev = nullptr;
            else
                m_pTail = nullptr;
        }

        else if (current == m_pTail)
        {
            m_pTail = current->m_pPrev;
            m_pTail->m_pNext = nullptr;
        }

        else
        {
            current->m_pPrev->m_pNext = current->m_pNext;
            current->m_pNext->m_pPrev = current->m_pPrev;
        }

        delete current;
    }
};

int main()
{
    CDoublyLinkedList<int> list;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    cout << "Lista enlazada doble después de inserciones:" << endl;
    list.Print();

    cout << "Eliminando 20 de la lista." << endl;
    list.Delete(20);
    list.Print();

    return 0;
}
