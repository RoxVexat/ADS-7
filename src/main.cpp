// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"
#include <cstdlib>
#include <ctime>


int main() 
{
    std::srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "n\tfalse\t\ttrue\t\trndom\n";

    for (int carriageCount = 2; carriageCount <= 100; carriageCount++) 
    {
        int operationsFalse;
        int operationsTrue;
        int operationsRandom;

        {
            Train train;
            for (int i = 0; i < carriageCount; i++)
                train.addCar(false);
            train.getLength();
            operationsFalse = train.getOpCount();
        }

        {
            Train train;
            for (int i = 0; i < carriageCount; i++)
                train.addCar(true);
            train.getLength();
            operationsTrue = train.getOpCount();
        }

        {
            Train train;
            for (int i = 0; i < carriageCount; i++)
                train.addCar(std::rand() % 2);
            train.getLength();
            operationsRandom = train.getOpCount();
        }

        std::cout << carriageCount << "\t"
          << operationsFalse << "\t\t"
          << operationsTrue << "\t\t"
          << operationsRandom << "\n";
    }

    return 0;
}
