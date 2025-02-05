#include <iostream>
using namespace std;

struct NODE
{
    int m_data;
    struct NODE *m_pNext;
};

class CCircularLinkedList
{
private:
    NODE *m_pRoot;

public:
    CCircularLinkedList() : m_pRoot(nullptr) {}

    void Insert(int data)
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;

        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
            newNode->m_pNext = m_pRoot;
        }
        else
        {
            NODE* current = m_pRoot;
            while (current->m_pNext != m_pRoot)
            {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
            newNode->m_pNext = m_pRoot;
        }
    }

    void Print() const
    {
        if (m_pRoot == nullptr)
        {
            cout << "La lista está vacía." << endl;
            return;
        }

        NODE* current = m_pRoot;
        do
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        } while (current != m_pRoot);
        cout << "(vuelve a la raíz)" << endl;
    }

    void Delete(int data)
    {
        if (m_pRoot == nullptr)
        {
            cout << "La lista está vacía. No se puede eliminar." << endl;
            return;
        }

        NODE* current = m_pRoot, *prev = nullptr;

        if (m_pRoot->m_pNext == m_pRoot && m_pRoot->m_data == data)
        {
            delete m_pRoot;
            m_pRoot = nullptr;
            return;
        }

        if (m_pRoot->m_data == data)
        {
            prev = m_pRoot;
            while (prev->m_pNext != m_pRoot)
            {
                prev = prev->m_pNext;
            }
            NODE *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            prev->m_pNext = m_pRoot;
            delete temp;
            return;
        }

        do
        {
            prev = current;
            current = current->m_pNext;

            if (current->m_data == data)
            {
                prev->m_pNext = current->m_pNext;
                delete current;
                return;
            }

        } while (current != m_pRoot);

        cout << "El valor " << data << " no se encuentra en la lista." << endl;
    }
};

int main(int argc, char *argv[])
{
    CCircularLinkedList list;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    list.Print();

    cout << "Deleting 20 from the list." << endl;
    list.Delete(20);
    list.Print();

    cout << "Deleting 10 (root) from the list." << endl;
    list.Delete(10);
    list.Print();

    cout << "Trying to delete 100 (not in list)." << endl;
    list.Delete(100);

    return 0;
}
