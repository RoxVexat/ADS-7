// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train()
    : countOp(0), first(nullptr), current(nullptr){}

Train::~Train()
{
    if (!first) return;
    Car* carriage = first->next;
    while (carriage != first)
    {
        Car* toDelete = carriage->next;
        delete carriage;
        carriage = toDelete;
    }
    delete first;
}

void Train::addCar(bool light)
{
    Car* newCarriage = new Car{ light, nullptr, nullptr };
    if (!first)
    {
        first = newCarriage;
        first->next = first;
        first->prev = first;
        current = first;
    }
    else
    {
        Car* tail = first->prev;
        tail->next = newCarriage;
        newCarriage->prev = tail;
        newCarriage->next = first;
        first->prev = newCarriage;
    }
}

int Train::getLength()
{
    if (!first) return 0;
    resetOps();
    current = first;
    if (!current->light)
    {
        current->light = true;
    }
    int length = 0;
    bool completed = false;
    while (!completed)
    {
        while (true)
        {
            current = current->next;
            countOp++;
            length++;
            if (current->light)
            {
                current->light = false;
                break;
            }
        }
        int backSteps = 0;
        while (backSteps < length)
        {
            current = current->prev;
            countOp++;
            backSteps++;
        }
        if (!current->light)
        {
            completed = true;
        }
        else
        {
            length = 0;
        }
    }
    return length;
}

int Train::getOpCount()
{
    return countOp;
}

void Train::resetOps()
{
    countOp = 0;
}
