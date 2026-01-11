#include <iostream>
#include "ShoppingList.h"

int main(){
    ShoppingList list;
    while(true){
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std::cout << "Press '1' to add the product" << std::endl; 
        std::cout << "Press '2' to modify the product" << std::endl;
        std::cout << "Press '3' to see the receipt" << std::endl;
        std::cout << "Press '4' to exit" << std::endl;
        int choice = list.get_choice(1,4);
        if (choice == 1){
            list.clear_screen();
            list.add_product();
        }
        else if (choice == 2){ 
            list.clear_screen();
            list.modify_product();
        }
        else if (choice == 3){
            list.clear_screen();
            list.receipt();
        }
        else if (choice == 4){
            list.clear_screen();
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else{
            list.clear_screen();
            std::cout << "Wrong choice!" << std::endl;
        }
    }
    return 0;
}
    
