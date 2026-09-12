#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int evaluatePostfix(std::string expression) {
    std::stack<int> s;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if(token == "+"){
            int value = s.top();
            s.pop();
            value = s.top() + value;
            s.pop();

            s.push(value);
            continue;
        }
        if(token == "-"){
            int value = s.top();
            s.pop();
            value =s.top() - value;
            s.pop();

            s.push(value);
            continue;
        }
        if(token == "*"){
            int value = s.top();
            s.pop();
            value = s.top() * value;
            s.pop();

            s.push(value);
            continue;
        }
        if(token == "/"){
            int value = s.top();
            s.pop();
            value = s.top() / value;
            s.pop();

            s.push(value);
            continue;
        }

        int value = std::stoi(token);
        s.push(value);
    }

    // Return the final result
    return s.top();
}

int main() {
    // Test cases
    std::cout << "2 3 4 * + = " << evaluatePostfix("2 3 4 * +") << std::endl; // Expected: 14
    std::cout << "5 1 2 + 4 * + 3 - = " << evaluatePostfix("5 1 2 + 4 * + 3 -") << std::endl; // Expected: 14
    
    return 0;
}

