#include <iostream>
#include <vector>
#include <stack>

std::vector<int> stockSpan(std::vector<int> &prices)
{
    int n = prices.size();
    std::vector<int> result(n, 0);
    std::stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[i] >= prices[st.top()])
        {
            st.pop();
        }

        if (st.empty()) {
            result[i] = i + 1;
        } else {
            result[i] = i - st.top();
        }

        st.push(i);
    }

    return result;
}

int main()
{

    std::vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> res = stockSpan(prices);

    std::cout << "Output: [";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << (i == res.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}