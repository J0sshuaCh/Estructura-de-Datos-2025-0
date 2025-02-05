#include <iostream>
using namespace std;

struct NODE 
{
	int m_data;
	NODE* m_pNext;
};

class Queue 
{
private:
	NODE* m_pFront;  // Apunta al nodo frontal (primer nodo insertado)
	NODE* m_pRear;   // Apunta al nodo trasero (último nodo insertado)
	
public:
	Queue() : m_pFront(nullptr), m_pRear(nullptr) {}  // Constructor que inicializa la cola vacía
	
	// Método para agregar un nodo al final de la cola (enqueue)
	void Enqueue(int data) 
	{
		NODE* newNode = new NODE;
		newNode->m_data = data;
		newNode->m_pNext = nullptr;
		
		if (m_pRear == nullptr) 
		{
			m_pFront = newNode;
			m_pRear  = newNode;
		}
		else
		{
			m_pRear->m_pNext = newNode;
			m_pRear = newNode;
		}
	}

	// Método alternativo con otro nombre (Insertar)
	void Insertar(int data)
	{
		Enqueue(data);
	}

	// Método para eliminar un nodo de la cola (dequeue)
	void Dequeue()
	{
		if (m_pFront == nullptr)
		{
			cout << "La cola está vacía, no se puede hacer dequeue." << endl;
			return;
		}
		NODE* temp = m_pFront;
		m_pFront = m_pFront->m_pNext;
		delete temp;

		if (m_pFront == nullptr)
		{
			m_pRear = nullptr;
		}
	}

	void Borrar()
	{
		Dequeue();
	}

	int Front() const {
		if (m_pFront == nullptr) {
			cout << "La cola está vacía." << endl;
			return -1;
		}
		return m_pFront->m_data;
	}

	bool IsEmpty() const {
		return m_pFront == nullptr;
	}

	void Print() const
	{
		if (m_pFront == nullptr) {
			cout << "La cola está vacía." << endl;
			return;
		}

		NODE* current = m_pFront;
		while (current != nullptr) {
			cout << current->m_data << " -> ";
			current = current->m_pNext;
		}
		cout << "nullptr" << endl;
	}
};

int main() {
	Queue queue;

	// Insertar algunos elementos en la cola
	queue.Insertar(10);
	queue.Insertar(20);
	queue.Insertar(30);
	queue.Insertar(5);

	// Imprimir la cola
	cout << "Contenido de la cola: ";
	queue.Print();

	// Ver el valor del frente de la cola
	cout << "Valor del frente de la cola: " << queue.Front() << endl;

	// Eliminar el valor frontal de la cola
	cout << "Haciendo borrar de la cola." << endl;
	queue.Borrar();
	queue.Print();

	// Ver el valor del frente de la cola después de hacer borrar
	cout << "Valor del frente de la cola después de hacer borrar: " << queue.Front() << endl;

	// Verificar si la cola está vacía
	if (queue.IsEmpty())
	{
		cout << "La cola está vacía." << endl;
	}
	else
	{
		cout << "La cola no está vacía." << endl;
	}

	return 0;
}