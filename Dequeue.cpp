#include "Dequeue.h"


// Function to return the size of the deque.

template<typename T>
int Deque<T>::size()
{
    return Size;
}

template<typename T>
bool Deque<T>::isEmpty()
{
    if (Size == 0)
        return true;
    else  return false;
}

// Function to insert an element at the beginning of the deque.
template <typename T>
void Deque<T> ::insertFront(T value)
{
    Node<T>* newNode = createnode(value);
    // If deque is empty then update the front and rear pointers.
    if (front == NULL) {
        rear = front = newNode;
    }
    // Otherwise insert at the beginning of the deque according to the algorithm described above.
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    // Increase the size of the queue by one.
    Size++;
}

// Function to insert an element at the end of the deque.
template <typename T>
void Deque<T> ::insertRear(T value)
{
    Node<T>* newNode = createnode(value);
    // If deque is empty then update the front and rear pointers.
    if (rear == NULL)
        front = rear = newNode;
    // Otherwise insert at the end of the deque according to the algorithm described above.
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }

    // Increase the size of the queue by one.
    Size++;
}

// Function to delete the element from the front end of the deque.
template <typename T>
void Deque<T>::deleteFront()
{
    // Check if the deque is empty.
    if (isEmpty())
        cout << "UnderFlow\n";

    // Otherwise, delete the element at the beginning of the deque according to the algorithm described above.
    else
    {
        Node<T>* temp = front;
        front = front->next;
        // If only one element was present in the deque.
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Decrease the size of the deque by one.
        Size--;
    }
}

// Function to delete the element from the rear end of the deque.
template <typename T>
void Deque<T>::deleteRear()
{
    // Check if the deque is empty.
    if (isEmpty())
        cout << "UnderFlow\n";
    // Otherwise delete the element at the end of the deque according to the algorithm described above.
    else
    {
        Node<T>* temp = rear;
        rear = rear->prev;
        // If only one element was present in the deque.
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        // Decrease the size of the deque by one.
        Size--;
    }
}

// Function to return the element at the front of the deque.
template <typename T>
T Deque<T> ::getFront()
{
    // If deque is empty, then return garbage value.
    if (isEmpty())
        return -1; // garbage value
    return front->value;
}

// Function to return the element at the back of the deque.
template <typename T>
T Deque<T> ::getRear()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->value;
}

// Function to check if the queue is full or not.
template <typename T>
bool Deque<T> ::isFull()
{
    if (Size == max_size)
        return true;
    else
        return false;
}

