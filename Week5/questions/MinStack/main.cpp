#include<iostream>
#include<stack>

using namespace std;

class MinStack {
    private:
    std::stack<int> mainstack;
    std::stack<int> minstack;
    public:
    MinStack() {}
    void push(int val){
        if(this->mainstack.empty()){
            cout << "i am here" << val << endl;

            this->mainstack.push(val);
            this->minstack.push(val);
        }else if (this->minstack.top() < val){
            cout << "i am here" << val << endl;
            this->mainstack.push(val);
            this->minstack.push(this->minstack.top());
        }else{
            cout << "i am here" << val << endl;

            this->mainstack.push(val);
            this->minstack.push(val);
        }
    }
    void pop(){
        if(this->mainstack.empty()){
            cout << "Stack Underflow!" << endl;
            return;
        }

        this->mainstack.pop();
        this->minstack.pop();
    }
    int top(){
        if(this->mainstack.empty()){
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return this->mainstack.top();
    }
    int getMin(){
        if(this->minstack.empty()){
            cout << "Stack Underflow!" << endl;
            return -1;
        }
         return this->minstack.top();
    }
};

int main(){

    MinStack MS;

    MS.push(5);
    MS.push(3);
    MS.push(7);

    int get_min = MS.getMin();
    cout << "smallest value in stack: " << get_min << endl;

    int get_top = MS.top();
    cout << "Top element in stack: " << get_top << endl;

    MS.pop();
    
    get_min = MS.getMin();
    cout << "smallest value in stack: " << get_min << endl;

    get_top = MS.top();
    cout << "Top element in stack: " << get_top << endl;

    return 0;
}