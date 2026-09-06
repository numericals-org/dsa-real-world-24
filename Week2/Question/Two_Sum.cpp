#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class solution {
    public:
    vector<int> TwoSum(const vector<int> list, int target){
        std::unordered_map<int, int> map;
        for(int i=0; i <list.size();i++){
            int complement = target - list[i];
            if(map.count(complement)){
                return {map[target-list[i]], i};
            }
            map[list[i]]=i;
        }

        return {};
    }
};

int main () {
    return 0;
}