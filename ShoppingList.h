#pragma once
#include <vector>
#include <string>

    /**
     * \class ShoppingList
     * 
     * Manages a collection of shopping items and provides functions for interaction.
     * The class uses parallel vectors to store product names, quantities and prices.
     * It includes built-in validation mechanisms for user input.
     * 
     */

class ShoppingList {
private:
    std::vector<std::string> m_name;
    std::vector<int> m_quantity;
    std::vector<double> m_price;

    /**
    * \brief Validates and gets a product name from the user.
    * 
    * Ensures that the name is not empty and does not exceed 20 characters.
    * 
    * \return A validated name as a std::string.
    */
    std::string get_name();

    /**
     * \brief Validates and gets a product quantity.
     * 
     * Ensures the input is a digit greater than 0 and verifies the input buffer. 
     * std::cin rejects non digit characters (like letters).
     * std::cin.peek() == '\n' rejects wrong values like "4k4". 
     * Additionally checks if the input is a integer, it rejects double values.
     * 
     * \return A validated quantity as an integer.
     */
    int get_quantity();

    /**
     * \brief Validates and gets a product price.
     * 
     * Works similarly to get_quantity() to ensure the input is valid.
     * 
     * @return A validated price as a double.
     */
    double get_price();

public: 
    /**
     * \brief Clears the terminal screen.
     * 
     * Shifts the text by 20 lines to improve readability of the displayed information.
     */
    void clear_screen();

    /**
     * \brief Validates and gets the user's menu choice.
     * 
     * Prevents invalid character inputs and ensures the selection is within 
     * the specified range.
     * It also informs user about possible choices.
     * 
     * \param min The minimum allowed option.
     * 
     * \param max The maximum allowed option.
     * 
     * \return The validated choice as an integer.
     */
    int get_choice(int min, int max);

    /**
     * \brief Adds a new product to the list.
     * 
     * Assigns a validated result from get_name() to a temporary variable.
     * Checks if a product with this name already exists.
     * If unique, assigns validated data to the temporary values 
     * by using results of the above mentioned functions.
     * Appends these values to the vectors using push_back().
     * 
     */
    void add_product();

    /**
     * \brief Modifies or deletes an existing product.
     * 
     * Searches the m_name vector for a match.
     * Updates name, quantity, and price at the current index 'i' 
     * using validation functions. 
     * Removes the product from all vectors using the erase() method 
     * at the matching index.
     * 
     */
    void modify_product();

    /**
     * \brief Displays a virtual receipt and provides list resets.
     * 
     * Uses std::setw() and iomanip to format the output. 
     * It provides an option to completely clear the shopping list by using 
     * clear() on all vectors.
     * 
     */
    void receipt();
};