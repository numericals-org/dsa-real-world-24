#include<iostream>
using namespace std;

template<typename T>

class Stack {
    private:
    T* data;
    int capacity;
    int topIndex;

    public:
    Stack(int cap) : capacity(cap), topIndex(-1){
        this->data = new T[cap];
    }
    ~Stack() {
        delete[] data;
    }
    void push(const T& val) {
        if(this->topIndex == this->capacity - 1){
            cout << "Stack Overflow!" << endl;
            return;
        }

        this->topIndex++;
        this->data[topIndex] = val;
    }
    void pop() {
        if(this->topIndex == -1){
            cout << "Stack Underflow!" << endl;
            return;
        }

        this->topIndex--;
    }
    T top() const {
        if(this->topIndex == -1){
            cout << "Stack Underflow!" << endl;
            return T();
        }
        return data[topIndex];
    }
    bool isEmpty() const {
       return this->topIndex == -1;
    }
    int size() const {
        return this->topIndex + 1;
    }
};


int main() {

    Stack<int> st(3);

    st.push(10);
    st.push(20);
    st.push(30);

    int top = st.top();
    cout << "stack top: " << top << endl;

    int size = st.size();
    cout << "stack top: " << size << endl;

    st.pop();

    top = st.top();
    cout << "stack top: " << top << endl;

    size = st.size();
    cout << "stack top: " << size << endl;

    st.push(40);
    st.push(50);

    return 0;
}