#include "DeliveredPizza.h"

DeliveredPizza::DeliveredPizza(std::string pizzaSize, std::string crustType, std::vector<std::string> toppings, std::string deliveryAddress)
: Pizza(pizzaSize, crustType, toppings)
{
    double pizzaPrice = this->getPrice();

    this->deliveryAdress = deliveryAddress;

    if (pizzaPrice > 20.00)
        this->deliveryFee = 3.50;
    else if (pizzaPrice <= 20.00)
        this->deliveryFee = 5.00;
}

std::ostream& operator<<(std::ostream& output, DeliveredPizza& oneDelPizza)
{
    output.precision(2);

    output << std::fixed << "\nYou ordered a " << oneDelPizza.getPizzaSize() << " " << oneDelPizza.getPizzaType() << " with ";

    for (std::string topping : oneDelPizza.getTopppings())
    {
        output << topping << " ";
    }

    output << "\n\n\tPizza Price:  $" << oneDelPizza.getPrice();
    output << "\n\tDelivery Fee: $" << oneDelPizza.deliveryFee;
    output << "\n\tTotal Price:  $" << oneDelPizza.getPrice() + oneDelPizza.deliveryFee;
    output << "\n\nDelivered to: " << oneDelPizza.deliveryAdress;
    return output;
}
