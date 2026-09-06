#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

struct Node
{
    std::string key;
    int value;
    Node *next;

    Node(const std::string &k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap
{
private:
    Node **buckets;
    int cap;
    int size;

public:
    HashMap(int cap) : cap(cap), size(0)
    {
        buckets = new Node *[cap];
        for (int i = 0; i < cap; i++)
        {
            buckets[i] = nullptr;
        }
    }
    int getHashIndex(const std::string &key) const
    {

        if (key.empty())
            return 0;

        int sum = 0;
        for (char k : key)
        {
            sum += k;
        }
        return (sum % this->cap);
    }
    void insert(const std::string &key, int value)
    {
        int idx = getHashIndex(key);

        Node *current = buckets[idx];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node *newNode = new Node(key, value);
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
        this->size++;
    }
    int get(const std::string &key) const
    {
        int idx = getHashIndex(key);
        Node *current = buckets[idx];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }

        return -1;
    }
    void remove(const std::string &key)
    {
        int idx = getHashIndex(key);
        Node *current = buckets[idx];

        if (current == nullptr)
        {
            return;
        }
        else if (current->key == key)
        {
            buckets[idx] = current->next;
            delete current;
            this->size--;
            return;
        }
        else
        {

            Node *prev = current;
            current = current->next;

            while (current != nullptr)
            {
                if (current->key == key)
                {
                    prev->next = current->next;
                    delete current;
                    this->size--;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        return;
    }
    bool contains(const std::string &key) const
    {
        int idx = getHashIndex(key);
        Node *current = buckets[idx];

        while(current != nullptr){
            if(current->key == key){
                return true;
            }
            current = current->next;
        }

        return false;
    }
    ~HashMap(){
        for(int i=0; i<cap; i++){
            Node *current = buckets[i];
            while(current != nullptr){
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] buckets;
    }
};


void testHashMap() {
    std::cout << "=== Testing HashMap ===\n\n";
    
    // Test 1: Basic insert and get
    std::cout << "Test 1: Basic insert and get... ";
    HashMap map(10);
    map.insert("alice", 25);
    map.insert("bob", 30);
    map.insert("charlie", 35);
    
    assert(map.get("alice") == 25);
    assert(map.get("bob") == 30);
    assert(map.get("charlie") == 35);
    std::cout << "PASSED\n";
    
    // Test 2: Key not found
    std::cout << "Test 2: Key not found... ";
    assert(map.get("david") == -1);
    std::cout << "PASSED\n";
    
    // Test 3: Update existing key
    std::cout << "Test 3: Update existing key... ";
    map.insert("alice", 26);  // Update alice's age
    assert(map.get("alice") == 26);
    std::cout << "PASSED\n";
    
    // Test 4: Contains
    std::cout << "Test 4: Contains... ";
    assert(map.contains("alice") == true);
    assert(map.contains("david") == false);
    std::cout << "PASSED\n";
    
    // Test 5: Remove
    std::cout << "Test 5: Remove... ";
    map.remove("bob");
    assert(map.get("bob") == -1);
    assert(map.contains("bob") == false);
    assert(map.contains("alice") == true);  // Others still exist
    std::cout << "PASSED\n";
    
    // Test 6: Remove non-existent key (should not crash)
    std::cout << "Test 6: Remove non-existent key... ";
    map.remove("nonexistent");
    std::cout << "PASSED\n";
    
    // Test 7: Collision handling (multiple keys, same hash)
    std::cout << "Test 7: Collision handling... ";
    HashMap smallMap(3);  // Small capacity to force collisions
    smallMap.insert("abc", 1);  // hash = 97+98+99 = 294, 294%3 = 0
    smallMap.insert("bca", 2);  // hash = 98+99+97 = 294, 294%3 = 0 (collision!)
    smallMap.insert("cab", 3);  // hash = 99+97+98 = 294, 294%3 = 0 (collision!)
    
    assert(smallMap.get("abc") == 1);
    assert(smallMap.get("bca") == 2);
    assert(smallMap.get("cab") == 3);
    std::cout << "PASSED\n";
    
    // Test 8: Remove from collision chain
    std::cout << "Test 8: Remove from collision chain... ";
    smallMap.remove("bca");  // Remove middle of chain
    assert(smallMap.get("bca") == -1);
    assert(smallMap.get("abc") == 1);  // Others still exist
    assert(smallMap.get("cab") == 3);
    std::cout << "PASSED\n";
    
    std::cout << "\n=== All tests passed! ===\n";
}

void benchmarkInsertions(int n) {
    std::cout << "\n=== Benchmarking " << n << " insertions ===\n";
    
    // Generate random keys
    std::vector<std::string> keys;
    for (int i = 0; i < n; i++) {
        keys.push_back("key_" + std::to_string(i));
    }
    
    // Benchmark YOUR HashMap
    auto start = std::chrono::high_resolution_clock::now();
    HashMap myMap(n);  // Capacity = n
    for (int i = 0; i < n; i++) {
        myMap.insert(keys[i], i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto myMapTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Benchmark std::unordered_map
    start = std::chrono::high_resolution_clock::now();
    std::unordered_map<std::string, int> stdMap;
    for (int i = 0; i < n; i++) {
        stdMap[keys[i]] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    auto stdMapTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Your HashMap:     " << myMapTime.count() << " microseconds\n";
    std::cout << "std::unordered_map: " << stdMapTime.count() << " microseconds\n";
    std::cout << "Ratio (yours/std): " << (double)myMapTime.count() / stdMapTime.count() << "x\n";
}

void benchmarkLookups(int n) {
    std::cout << "\n=== Benchmarking " << n << " lookups ===\n";
    
    // Setup: create maps with n elements
    HashMap myMap(n);
    std::unordered_map<std::string, int> stdMap;
    
    for (int i = 0; i < n; i++) {
        std::string key = "key_" + std::to_string(i);
        myMap.insert(key, i);
        stdMap[key] = i;
    }
    
    // Benchmark YOUR HashMap lookups
    int sum1 = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        std::string key = "key_" + std::to_string(i);
        sum1 += myMap.get(key);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto myMapTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Benchmark std::unordered_map lookups
    int sum2 = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        std::string key = "key_" + std::to_string(i);
        sum2 += stdMap[key];
    }
    end = std::chrono::high_resolution_clock::now();
    auto stdMapTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Your HashMap:     " << myMapTime.count() << " microseconds\n";
    std::cout << "std::unordered_map: " << stdMapTime.count() << " microseconds\n";
    std::cout << "Ratio (yours/std): " << (double)myMapTime.count() / stdMapTime.count() << "x\n";
    
    // Verify correctness
    if (sum1 != sum2) {
        std::cout << "WARNING: Results don't match!\n";
    }
}

int main() {
    // testHashMap();
    std::cout << "=== HASH MAP PERFORMANCE BENCHMARK ===\n";
    
    // Test with different sizes
    benchmarkInsertions(1000);
    benchmarkLookups(1000);
    
    benchmarkInsertions(10000);
    benchmarkLookups(10000);
    
    benchmarkInsertions(100000);
    benchmarkLookups(100000);
    return 0;
}