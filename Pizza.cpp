#include "Pizza.h"

// Private
double Pizza::calcPrice()
{
    if (this->pizzaSize.compare("small") == 0)
        return 10.00 + this->toppings.size() * 2.00;
    else if (this->pizzaSize.compare("medium") == 0)
        return 14.00 + this->toppings.size() * 2.00;
    else if (this->pizzaSize.compare("large") == 0)
        return 17.00 + this->toppings.size() * 2.00;

    return -1;
}


// Public
Pizza::Pizza(std::string pizzaSize, std::string pizzaType, std::vector<std::string> toppings)
{
    this->pizzaSize = pizzaSize;
    this->pizzaType = pizzaSize;
    this->toppings = toppings;
    this->price = price;
}


std::string Pizza::getPizzaSize() { return this->pizzaSize; }
std::string Pizza::getPizzaType() { return this->pizzaType; }
std::vector<std::string> Pizza::getTopppings() { return this->toppings; }
double Pizza::getPrice() { return this->price; }


std::ostream& operator<<(std::ostream& output, const Pizza& onePizza)
{
    output << "\nYou ordered a " << onePizza.pizzaSize << " " << onePizza.pizzaType << " with ";

    for (std::string topping : onePizza.toppings)
    {
        output << topping << " ";
    }

    output << "\n\tPizza Price: $" << onePizza.price;
    return output;
}
