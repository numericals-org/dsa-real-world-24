#include <iostream>
#include <string>
#include <stack>

bool isBalanced(std::string expr)
{
    std::stack<char> s;

    for (char c : expr)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
                return false;

            char top = s.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{'))
            {
                s.pop();
            }
            else
            {
                return false; // Mismatch!
            }
        }
    }

    return s.empty();
}

int main()
{

    std::cout << "()[]{} : " << (isBalanced("()[]{}") ? "Valid" : "Invalid") << std::endl;
    std::cout << "([)] : " << (isBalanced("([)]") ? "Valid" : "Invalid") << std::endl;
    std::cout << "{[()]} : " << (isBalanced("{[()]}") ? "Valid" : "Invalid") << std::endl;

    return 0;
}