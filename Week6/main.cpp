#include<iostream>
using namespace std;

template<typename T>
class Queue {
    private:
    T* data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;

    public:
    Queue(int cap): capacity(cap), frontIndex(0), rearIndex(-1), size(0) {
        this->data = new T[cap];
    }
    ~Queue() {
        delete[] data;
    }
    void enqueue(const T& val){
        if(this->size == this->capacity){
            cout << "Queue Overflow!" << endl;
            return;
        }

        this->rearIndex = (this->rearIndex + 1) % this->capacity;
        this->data[this->rearIndex] = val;
        this->size++;
    }
    T dequeue() {
        if(this->size == 0){
            cout << "Queue Underflow!" <<endl;
            return T();
        }

        T val = this->data[this->frontIndex];
        this->frontIndex = (this->frontIndex + 1) % this->capacity;
        this->size--;

        return val;
    }
    T front() const {
        if(this->size == 0){
            cout << "Queue Underflow!" <<endl;
            return T();
        }

        return this->data[this->frontIndex];
    }
    bool isEmpty() const {
        return this->size == 0;
    }
    int getSize() const {
        return this->size;
    }
};

int main (){

    Queue<int> queue(3);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    cout << "front in the queue is: " << queue.front() << endl;
    cout << "the size of queue is: " << queue.getSize() << endl;
    
    queue.dequeue();
    
    queue.enqueue(40);
    
    cout << "front in the queue is: " << queue.front() << endl;
    cout << "the size of queue is: " << queue.getSize() << endl;
    
    queue.enqueue(50);

    return 0;
}
