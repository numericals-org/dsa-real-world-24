#include<iostream>
using namespace std;


template<typename T>
struct Node {
    T data;
    Node *next;
    Node(const T& i) : data(i), next(nullptr) {}
};

template<typename T>
class LinkedListStack {
    private:
    Node<T> *head;
    int size;

    public:
    LinkedListStack(): head(nullptr), size(0) {}
    ~LinkedListStack(){
        Node<T> *current = this->head;
        while(current != nullptr){
            Node<T> *temp = current;
            current = current->next;

            delete temp;
        }
    }
    void push(const T& val) {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }
    void pop() {
        if(this->size == 0){
            cout << "Stack Underflow!" << endl;
            return;
        }
        
        Node<T> *current = this->head;
        this->head = current->next;
        delete current;
        this->size--;
    }
    T top() const {
        if(this->size == 0){
            cout << "Stack Underflow!" << endl;
            return T();
        }

        return this->head->data;
    }
    bool isEmpty() const {
        return this->size == 0;
    }
    int getSize() const {
        return this->size;
    }
};

int main() {

    LinkedListStack<int> stack;
     stack.push(200);
     stack.push(300);
     stack.push(400);

     int val = stack.top();
     int size = stack.getSize();

     cout << "top value is: " << val << endl;
     cout << "size of stack is: " << size << endl;
     
     stack.pop();

     val = stack.top();
     size = stack.getSize();
     
     cout << "top value is: " << val << endl;
     cout << "size of stack is: " << size << endl;
    return 0;
}