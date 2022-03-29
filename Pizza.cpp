#include "Pizza.h"

// Private
double Pizza::calcPrice()
{
    if (this->pizzaSize.compare("small") == 0)
        return 10.00 + (this->toppings.size() - 1) * 2.00;
    else if (this->pizzaSize.compare("medium") == 0)
        return 14.00 + (this->toppings.size() - 1) * 2.00;
    else if (this->pizzaSize.compare("large") == 0)
        return 17.00 + (this->toppings.size() - 1) * 2.00;

    return -1;
}


// Public
Pizza::Pizza(std::string pizzaSize, std::string crustType, std::vector<std::string> toppings)
{
    this->pizzaSize = pizzaSize;
    this->crustType = crustType;
    this->toppings = toppings;
    this->price = this->calcPrice();
}


std::string Pizza::getPizzaSize() { return this->pizzaSize; }
std::string Pizza::getPizzaType() { return this->crustType; }
std::vector<std::string> Pizza::getTopppings() { return this->toppings; }
double Pizza::getPrice() { return this->price; }


std::ostream& operator<<(std::ostream& output, const Pizza& onePizza)
{
    output.precision(2);

    output << std::fixed << "\nYou ordered a " << onePizza.pizzaSize << " " << onePizza.crustType << " with ";

    for (std::string topping : onePizza.toppings)
    {
        output << topping << " ";
    }

    output << "\n\n\tPizza Price: $" << onePizza.price;
    return output;
}
