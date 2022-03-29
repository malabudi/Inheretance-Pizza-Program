#include "Pizza.h"

#ifndef DELIVEREDPIZZA_H
#define DELIVEREDPIZZA_H

class DeliveredPizza : public Pizza
{
    private:
        double deliveryFee;
        double totalPrice;
        std::string deliveryAdress;

    public:
        DeliveredPizza(std::string pizzaSize, std::string crustType, std::vector<std::string> toppings, std::string deliveryAddress);

        friend std::ostream& operator<<(std::ostream& output, DeliveredPizza& oneDelPizza);
};

#endif
