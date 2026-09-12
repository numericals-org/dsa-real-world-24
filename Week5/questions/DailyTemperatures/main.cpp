#include<iostream>
#include<vector>
#include<stack>

std::vector<int> dailyTemperatures (std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> result(n, 0);
    std::stack<int> st;

    for(int i =0; i < n; i++){

        while(!st.empty() && temperatures[i] > temperatures[st.top()]){
            int index = st.top();
            st.pop();
            result[index] = i - index;
        }

        st.push(i);
    }

    return result;
};

int main() {
    std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> res = dailyTemperatures(temps);
    
    std::cout << "Output: [";
    for(int i=0; i<res.size(); i++) {
        std::cout << res[i] << (i == res.size()-1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    
    return 0;
}