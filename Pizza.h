#include <vector>
#include <string>
#include <iostream>

#ifndef PIZZA_H
#define PIZZA_H

class Pizza
{
    private:
        std::string pizzaSize;
        std::string crustType;
        std::vector<std::string> toppings;
        double price;

        double calcPrice();

    public:
        Pizza(std::string pizzaSize, std::string crustType, std::vector<std::string> toppings);

        // Accessors
        std::string getPizzaSize();
        std::string getPizzaType();
        std::vector<std::string> getTopppings();
        double getPrice();

        friend std::ostream& operator<<(std::ostream& output, const Pizza& onePizza);
};

#endif
