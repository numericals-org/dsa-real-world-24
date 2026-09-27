#include<iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;
    Node(T i) : data(i), next(nullptr) {}
};

template<typename T>
class LinkedListQueue {
    private:
    Node<T>* front;
    Node<T>* rear;
    int size;

    public:
    LinkedListQueue(): front(nullptr), rear(nullptr), size(0) {}
    ~LinkedListQueue(){
        while(this->front != nullptr){
            Node<T>* temp = this->front;
            this->front = this->front->next;
            delete temp;
        }
    }
    void enqueue(const T& val) {
         Node<T>* newNode = new Node<T>(val); 
        if(this->size == 0){
            this->front = newNode;
            this->rear = newNode;
            size += 1;
            return;
        }

        this->rear->next = newNode;
        this->rear = newNode;
        this->size += 1;
    }
    T dequeue() {
        if(this->size == 0){
            cout << "Queue is underflow" << endl;
            return T();
        }
        Node<T>* temp = this->front;
        this->front = this->front->next;

        if(this->front == nullptr){
            this->rear = nullptr;
        }

        T val = temp->data;
        delete temp;
        this->size -= 1;

        return val;
    }
    T frontValue() const{
        if(this->size == 0){
            cout << "Queue is underflow" << endl;
            return T();
        }
        return this->front->data;
    }
    bool isEmpty() const {
        return this->size == 0;
    }
    int getSize() const {
        return this->size;
    }
};

int main () {

    LinkedListQueue<int> queue;

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    cout << "front value is: " << queue.frontValue() << endl;
    cout << "queue size is: " << queue.getSize() << endl;
    
    int val = queue.dequeue();

    cout << val << endl;
    cout << "front value is: " << queue.frontValue() << endl;
    cout << "queue size is: " << queue.getSize() << endl;

    return 0;
}