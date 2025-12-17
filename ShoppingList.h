#pragma once
#include <vector>
#include <string>

class ShoppingList {
private:
    std::vector<std::string> m_name;
    std::vector<int> m_quantity;
    std::vector<double> m_price;

    std::string get_name();
    int get_quantity();
    double get_price();

public: 
    void clear_screen();
    int get_choice(int min, int max);
    void add_product();
    void modify_product();
    void receipt();
};