#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Product
{
    int id;
    std::string name;
    std::string brand;
    double price;
};

class ProductCatalog
{
private:
    std::unordered_map<int, Product> products;
    std::vector<Product> productsByName;
    std::vector<Product> productsByPrice;
    std::vector<Product> productsById;

public:
    void addProduct(const Product &p)
    {
        this->products[p.id] = p;
        this->productsByName.push_back(p);
        this->productsByPrice.push_back(p);
        this->productsById.push_back(p);
    }
    void sortCatalog()
    {
        std::sort(this->productsById.begin(), this->productsById.end(),
                  [](const Product &a, const Product &b)
                  {
                      return a.id < b.id;
                  });
        std::sort(this->productsByName.begin(), this->productsByName.end(),
                  [](const Product &a, const Product &b)
                  {
                      return a.name < b.name;
                  });
        std::sort(this->productsByPrice.begin(), this->productsByPrice.end(),
                  [](const Product &a, const Product &b)
                  {
                      return a.price < b.price;
                  });
    }
    Product* searchProductByName(const std::string& name){
        int left=0, right= static_cast<int>(this->productsByName.size()-1);
        while(left <= right){
            int mid = left + (right-left)/2;
            if(this->productsByName[mid].name == name){
                return &this->productsByName[mid];
            }
            else if (this->productsByName[mid].name < name){
                left = mid + 1;
            }else{
                right= mid-1;
            }
        }

        return nullptr;
    }
    std::vector<Product*> getProductsByPriceRange(double minPrice, double maxPrice){
        std::vector<Product*> result;

        auto it_start = std::lower_bound(this->productsByPrice.begin(), this->productsByPrice.end(), minPrice, 
        [](const Product& p, double val) {
            return p.price < val; 
        });

        auto it_end = std::upper_bound(this->productsByPrice.begin(), this->productsByPrice.end(), maxPrice,
        [](double val, const Product& p) {
            return val < p.price;
        });

        while(it_start != it_end){
            result.push_back(&(*it_start));
            ++it_start;
        }

        return result;
    }
};

int main()
{
    return 0;
}