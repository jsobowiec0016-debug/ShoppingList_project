#include "ShoppingList.h"
#include <iostream>
#include <iomanip>

    std::string ShoppingList::get_name(){
        std::string name;
        while(true){
            std::cout << "Name: ";
            std::getline(std::cin, name);
            if (!name.empty()){
                if(name.size() < 20){
                    return name;
                }
                else{
                    std::cout << "Name is too long! " << std::endl;
                }                   
            }
            else{
                std::cout << "Name cant be empty!" << std::endl;
            }   
        }
    }

    int ShoppingList::get_quantity(){
        double quantity;
        while(true){
            std::cout << "Quantity: ";
            if (std::cin >> quantity && quantity > 0 && std::cin.peek() == '\n') {
                if (quantity == int(quantity)){
                    return quantity;
                }
                else{
                    std::cout << "Quantity must be an integer!" << std::endl;
                }
            }
            else{
                std::cout << "Invalid quantity!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
    }

    double ShoppingList::get_price(){
        double price;
        while(true){
            std::cout << "Price: ";
            if (std::cin >> price && price > 0 && std::cin.peek() == '\n') {
                return price;
            }
            else{
                std::cout << "Invalid price!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
    }

    void ShoppingList::clear_screen() {
        for(int i = 0; i < 20; i++){
            std::cout << std::endl;
        }
    }

    int ShoppingList::get_choice(int min, int max){
        int choice;
        while(true){
            std::cout << "Your choice: ";
            if (std::cin >> choice && std::cin.peek() == '\n'){
                if (choice >= min && choice <= max){
                    std::cin.ignore(1000, '\n');
                    return choice;
                }
                std::cout << "Choice must be between " << min << " - " << max << '!' << std::endl;
            }
            else{
                std::cout << "Choice must be a number!" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(1000, '\n');
            }
        }
    }

    void ShoppingList::add_product(){
        while(true){
            std::cout << std::endl;
            std::cout << "Options: " << std::endl;
            std::cout << "Press '1' to add new product" << std::endl;
            std::cout << "Press '2' to exit" << std::endl; 
            int choice = get_choice(1,2);
            clear_screen();
            if (choice == 1){  
                std::string name;
                double quantity;
                double price;
                std::cout << "Adding product: " << std::endl;
                name = get_name();

                bool duplicate = false;
                for (int i=0; i < m_name.size(); i++){
                    if(name == m_name[i]){
                        std::cout << "Product " << name << " already exists!" << std::endl;
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate){
                    quantity = get_quantity();
                    price = get_price();    
                    m_name.push_back(name);
                    m_quantity.push_back(quantity);
                    m_price.push_back(price); 
                    std::cout << "New product has been added!" << std::endl;
                }   
            }
              
            else if (choice == 2){
                return;
            }
            else{
                clear_screen();
                std::cout << "Wrong choice!" << std::endl;
            }
        }
        clear_screen();
    }

    void ShoppingList::modify_product(){
        while(true){
            std::cout << std::endl;
            std::cout << "Options: " << std::endl;
            std::cout << "Press '1' to exit" << std::endl; 
            std::cout << "Press '2' to modify the product" << std::endl;
            std::string name;
            int choice = get_choice(1,2);
            if (choice == 1){
                clear_screen();
                return;
            }
            else if (choice == 2){
                std::cout << std::endl;
                std::cout << "Options: " << std::endl;
                std::cout << "Press '1' to exit" << std::endl;
                std::cout << "Press '2' to edit the product" << std::endl; 
                std::cout << "Press '3' to delete the product" << std::endl;
                int choice = get_choice(1,3);
                if(choice == 1){
                    return;
                }
                else if(choice==2){
                    clear_screen();
                    std::cout << "Modifying product: " << std::endl;
                    name = get_name();
                    bool found = false;
                    for (int i=0; i < m_name.size(); i++){
                        if(name == m_name[i]){
                            std::cout << "Current product: " << std::endl << "Name: " << m_name[i] << "     Quantity: " << m_quantity[i] << "      Price: " << m_price[i] << std::endl;
                            std::cout << "Changed: " << std::endl;
                            m_name[i] = get_name();
                            m_quantity[i] = get_quantity();
                            m_price[i] = get_price();
                            std::cout << "Product has been modified!" << std::endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        std::cout << "The name is invalid!";
                    }
                }
                else if (choice == 3){
                    clear_screen();
                    std::cout << "Deleting product: " << std::endl;
                    name = get_name();
                    bool found = false;
                    for (int i=0; i < m_name.size(); i++){
                        if(name == m_name[i]){
                            m_name.erase(m_name.begin() + i);
                            m_quantity.erase(m_quantity.begin() + i);
                            m_price.erase(m_price.begin() + i);
                            std::cout << "Product has been deleted!" << std::endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        std::cout << "The name is invalid!";
                    }
                }
                else{
                    std::cout << "Wrong choice!" << std::endl;
                }
            }
            else {
                std::cout << "Wrong choice!" << std::endl;
            }
        }
    }
    
    void ShoppingList::receipt(){
        std::cout << std::endl;
        std::cout << "Receipt: " << std::endl;
        std::cout << std::left << std::setw(20) << "Name"
        << std::right << std::setw(10) << "Quantity"
        << std::right << std::setw(12) << "Price"
        << std::right << std::setw(12) << "Total"
        << std::endl;
        double expense = 0;
        for (int i=0; i < m_name.size(); i++){
            double total = m_quantity[i]*m_price[i];
            expense += total;
            std::cout << std::left << std::setw(20) << m_name[i]
            << std::right << std::setw(10) << m_quantity[i]
            << std::right << std::setw(12) << m_price[i]
            << std::right << std::setw(12) << total
            << std::endl;    
        }       
        std::cout << std::endl; 
        std::cout << "Total price: " << expense << std::endl;
        std::cout << std::endl;
        std::cout << "Options: " << std::endl;
        std::cout << "Press '1' to exit" << std::endl;
        std::cout << "Press '2' to reset the receipt" << std::endl; 
        int choice = get_choice(1,2);
        if (choice == 1){
            clear_screen();
            return;
        }
        else if (choice == 2){
            m_name.clear();
            m_quantity.clear();
            m_price.clear();
            std::cout << "Reset has been made!" << std::endl;
        }   
        else{
            clear_screen();
            std::cout << "Wrong choice!" << std::endl;
        }
    }