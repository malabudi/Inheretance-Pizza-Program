#include "Pizza.h"

class DeliveredPizza : public Pizza
{
    private:
        double deliveryFee;
        double totalPrice;
        std::string deliveryAdress;

    public:
        DeliveredPizza(deliveryAdress);

        friend ostream& operator<<(ostream& output, const DeliveredPizza oneDelPizza);
};
