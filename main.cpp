#include <iostream>
#include "Pizza.h"
#include "DeliveredPizza.h"
#define NUMTOPPINGS 6

// Function prototypes
void askCustomerPizza(std::string& pizzaSize, std::string& crustType, std::vector<std::string>& userToppings, const std::string toppings[]);
bool askDelivery();

int main()
{
    const std::string toppings[] = {"Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"};

    std::vector<std::string> userToppings;
    std::string pizzaSize, crustType, deliveryAddress;
    int deliveryChoice;

    askCustomerPizza(pizzaSize, crustType, userToppings, toppings);

    // Does the user want delivery
    std::cout << "\nWould you like 1 - pick up or 2 - delivery? ";
    std::cin >> deliveryChoice;

    // Data validation
    while (deliveryChoice > 2 || deliveryChoice < 1)
    {
        std::cout << "\nInvalid selection, please select a valid option in the menu below\n";

        std::cout << "\nWould you like 1 - pick up or 2 - delivery? ";
        std::cin >> deliveryChoice;
    }

    if (deliveryChoice == 1)
    {
        Pizza userPizza(pizzaSize, crustType, userToppings);
        std::cout << userPizza;
    }
    else if (deliveryChoice == 2)
    {
        std::cin.ignore(1000, '\n');

        std::cout << "\nPlease enter your address:";
        std::cout << "\n\n\t";
        std::getline(std::cin, deliveryAddress);

        DeliveredPizza userDeliveredPizza(pizzaSize, crustType, userToppings, deliveryAddress);
        std::cout << userDeliveredPizza;
    }


    return 0;
}


void askCustomerPizza(std::string& pizzaSize, std::string& crustType, std::vector<std::string>& userToppings, const std::string toppings[])
{
    int sizeChoice, crustChoice, oneToppingChoice = -1;
    std::string userChosenTopping;
    std::vector<std::string> userToppingsVector;

    // Size
    std::cout << "\nWhat size pizza would you like to order?";
    std::cout << "\n\t1 - Small";
    std::cout << "\n\t2 - Medium";
    std::cout << "\n\t3 - Large";
    std::cout << "\n------> ";
    std::cin >> sizeChoice;

    // Data validation
    while (sizeChoice > 3 || sizeChoice < 1)
    {
        std::cout << "\nInvalid selection, please select a valid option in the menu below\n";

        std::cout << "\nWhat size pizza would you like to order?";
        std::cout << "\n\t1 - Small";
        std::cout << "\n\t2 - Medium";
        std::cout << "\n\t3 - Large";
        std::cout << "\n------> ";
        std::cin >> sizeChoice;
    }

    // Size Choice
    switch (sizeChoice)
    {
        case 1:
            pizzaSize = "small";
            break;
        case 2:
            pizzaSize = "medium";
            break;
        case 3:
            pizzaSize = "large";
            break;
    }


    // Crust
    std::cout << "\nWhat type of crust would you like to order?";
    std::cout << "\n\t1 - Classic";
    std::cout << "\n\t2 - Deep Dish";
    std::cout << "\n\t3 - Thin Crust";
    std::cout << "\n------> ";
    std::cin >> crustChoice;

    // Data validation
    while (crustChoice > 3 || crustChoice < 1)
    {
        std::cout << "\nInvalid selection, please select a valid option in the menu below\n";

        std::cout << "\nWhat type of crust would you like to order?";
        std::cout << "\n\t1 - Classic";
        std::cout << "\n\t2 - Deep Dish";
        std::cout << "\n\t3 - Thin Crust";
        std::cout << "\n------> ";
        std::cin >> crustChoice;
    }

    // Crust choice
    switch (crustChoice)
    {
        case 1:
            crustType = "classic";
            break;
        case 2:
            crustType = "deep dish";
            break;
        case 3:
            crustType = "thin crust";
            break;
    }


    // Toppings
    while (oneToppingChoice != 0)
    {
        std::cout << "\nChoose from the following toppings or 0 to quit";

        for (int i = 0; i < 6; ++i)
        {
            std::cout << "\n\t" << i + 1 << " - " << toppings[i];
        }

        std::cout << "\n------> ";
        std::cin >> oneToppingChoice;

        // Data validation
        while (oneToppingChoice > 6 || oneToppingChoice < 0)
        {
            std::cout << "\nInvalid selection, please select a valid option in the menu below\n";
            std::cout << "\nChoose from the following toppings or 0 to quit";

            for (int i = 0; i < 6; ++i)
            {
                std::cout << "\n\t" << i + 1 << " - " << toppings[i];
            }

            std::cout << "\n------> ";
            std::cin >> oneToppingChoice;
        }

        // Topping choice
        userToppingsVector.push_back(toppings[oneToppingChoice - 1]);
    }

    userToppings = userToppingsVector;
}
