#ifndef LINKEDList_HPP
#define LINKEDList_HPP

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class linkedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(T data = nullptr) : data(data), next(nullptr) {}
    };
    Node* front;
    int num_elements;
public:
    linkedList();
    ~linkedList();
    linkedList(const linkedList& other) = delete;
    linkedList& operator=(const linkedList& other) = delete;

    int size() const;
    bool is_empty() const;
    void insertFirst(const T& element);
    void insertLast(const T& element);
    void insertAt(const T& element, int index);
    void insertOrdered(const T& element);
    T findElement(const T& element);
    T removeFirst();
    T removeLast();
    T removeAt(int index);
    T removeFoundElement(const T& element);
    T getFirst() const;
    T getLast() const;
};

template<class T>
linkedList<T>::linkedList() :
    front(nullptr), num_elements(0)
{
}

template <class T>
linkedList<T>::~linkedList()
{
    // Free allocated memory
    //WHILE not empty, remove delete one then elements-- then repeat until empty.
    while (!is_empty())
    {
        removeFirst();
    }
    //worked without but ok
}

template <class T>
int linkedList<T>::size() const {
    // Returns size of linkedList
    return num_elements;
}

template <class T>
bool linkedList<T>::is_empty() const {
    // Returns if empty or not
    return num_elements == 0;
}

template <class T>
void linkedList<T>::insertFirst(const T& element) {
    // Adds element at the beginning of the linkedList
    if (is_empty())
    {
        front = new Node(element);
        num_elements++;
    }
    else
    {
        Node* newNode = new Node(element);
        newNode->next = front;
        front = newNode;
        num_elements++;

    }

}
template <class T>
void linkedList<T>::insertLast(const T& element) {
    // Adds element at the end of the linkedList
    if (is_empty())
    {
        front = new Node(element);
        num_elements++;
    }
    else
    {
        Node* newNode = new Node(element);
        Node* walker = front;
        while (walker->next != nullptr)
        {
            walker = walker->next;
        }
        walker->next = newNode;
        num_elements++;
    }

}
template<class T>
inline void linkedList<T>::insertAt(const T& element, int index)
{
    // Adds element at the index of the linkedList
	if (index < 0 || index > num_elements)
	{
        cout << "Index: " << index << " num_elements: " << num_elements << endl;
		throw exception("Index out of bounds");
	}
	if (index == 0)
	{
		insertFirst(element);
	}
	else if (index == num_elements)
	{
		insertLast(element);
	}
	else
	{
		Node* newNode = new Node(element);
		Node* walker = front;
		for (int i = 0; i < index - 1; i++)
		{
			walker = walker->next;
		}
		newNode->next = walker->next;
		walker->next = newNode;
		num_elements++;
	}

}
template<class T>
inline void linkedList<T>::insertOrdered(const T& element)
{
    // Adds element in order of the linkedList
	if (is_empty())
	{
		insertFirst(element);
	}
	else
	{
		Node* newNode = new Node(element);
		Node* walker = front;
		Node* prevWalk = walker;
		while (walker != nullptr && walker->data > element)
		{
			prevWalk = walker;
			walker = walker->next;
		}
		if (walker == front)
		{
			insertFirst(element);
		}
		else if (walker == nullptr)
		{
			insertLast(element);
		}
		else
		{
			newNode->next = walker;
			prevWalk->next = newNode;
			num_elements++;
		}
	}

}
template<class T>
inline T linkedList<T>::findElement(const T& element)
{
    if (is_empty())
    {
        throw exception("linkedList is empty");
    }

    Node* walker = front;
    Node* prevWalk = nullptr;

    while (walker != nullptr)
    {
        if (walker->data == element)
        {
            if (prevWalk == nullptr)
            {
                // Element is at the front
                front = walker->next;
            }
            else
            {
                // Element is in the middle or end
                prevWalk->next = walker->next;
            }

            T data = walker->data;
            delete walker;
            num_elements--;
            return data;
        }

        prevWalk = walker;
        walker = walker->next;
    }
}
template <class T>
T linkedList<T>::removeFirst() {
    // Removes first element in the linkedList
    if (is_empty())
    {
        cout << "Remve first already empty";
        throw exception("Cant remove First, linkedList is already empty");
    }
    Node* temp = front;
    T data = temp->data;
    front = front->next;
    delete temp;
    num_elements--;


    return data;
}

template <class T>
T linkedList<T>::removeLast() {
    // Removes last element in the linkedList
    if (is_empty())
    {

        cout << "Remve last already empty";
        throw exception("Cant remove Last, linkedList is already empty");
    }
    if (num_elements == 1)
    {
        Node* dataFront = front;
        front->next = nullptr;
        num_elements--;
        return dataFront->data;
    }
    Node* walker = front;
    Node* prevWalk = walker;
    while (walker->next != nullptr)
    {
        prevWalk = walker;
        walker = walker->next;
    }
    prevWalk->next = nullptr;
    num_elements--;
    return walker->data;
}

template<class T>
inline T linkedList<T>::removeAt(int index)
{
    // Removes element at the index of the linkedList
	if (index < 0 || index >= num_elements)
	{
        cout << "Index: " << index << " num_elemfgjkghgents: " << num_elements << endl;
		throw exception("Index out of bounds");
	}
	if (index == 0)
	{
		return removeFirst();
	}
	else if (index == num_elements - 1)
	{
		return removeLast();
	}
	else
	{
		Node* walker = front;
		Node* prevWalk = walker;
		for (int i = 0; i < index; i++)
		{
			prevWalk = walker;
			walker = walker->next;
		}
		prevWalk->next = walker->next;
		num_elements--;
		return walker->data;
	}
}

template<class T>
inline T linkedList<T>::removeFoundElement(const T& element)
{
    if (is_empty())
    {
        cout << "linkedList is empty bruh" << endl;
        throw exception("linkedList is empty");
    }

    Node* walker = front;
    Node* prevWalk = nullptr;

    while (walker != nullptr)
    {
        if (walker->data == element)
        {
            if (prevWalk == nullptr)
            {
                // Element is at the front
                front = walker->next;
            }
            else
            {
                // Element is in the middle or end
                prevWalk->next = walker->next;
            }

            T data = walker->data;
            delete walker;
            num_elements--;
            return data;
        }

        prevWalk = walker;
        walker = walker->next;
    }

    return -1;
}




template <class T>
T linkedList<T>::getFirst() const {
    // Returns the first element in the linkedList
    if (is_empty())
    {

        throw exception("Cant get First, linkedList is empty");
    }
    return front->data;
}

template <class T>
T linkedList<T>::getLast() const {
    // Returns the last element in the linkedList
    if (is_empty())
    {

        throw exception("Cant get Last, linkedList is empty");
    }
    else
    {
        Node* walker = front;

        while (walker->next != nullptr)
        {
            walker = walker->next;
        }
        return walker->data;
    }
}

#endif