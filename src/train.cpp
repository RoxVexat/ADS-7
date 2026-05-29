// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : operations(0), head(nullptr), now(nullptr) {}

Train::~Train() {
    if (!head) return;
    Car* carriage = head->next;
    while (carriage != head) {
        Car* toErase = carriage;
        carriage = carriage->next;
        delete toErase;
    }
    delete head;
}

void Train::addCar(bool light) {
    Car* newCarriage = new Car{light, nullptr, nullptr};
    if (!head) {
        head = newCarriage;
        head->next = head;
        head->prev = head;
        now = head;
    } else {
        Car* tail = head->prev;
        tail->next = newCarriage;
        newCarriage->prev = tail;
        newCarriage->next = head;
        head->prev = newCarriage;
    }
}

void Train::moveForward() {
    now = now->next;
    ++operations;
}

void Train::moveBackward() {
    now = now->prev;
    ++operations;
}

int Train::getLength() {
    if (!head) return 0;
    resetCounter();
    now = head;

    if (!now->light) now->light = true;

    int length = 0;
    bool completed = false;

    while (!completed) {
        while (true) {
            moveForward();
            ++length;
            if (now->light) {
                now->light = false;
                break;
            }
        }
        for (int step = 0; step < length; ++step) moveBackward();
        if (!now->light) completed = true;
        else length = 0;
    }
    return length;
}

int Train::getOpCount() const {
    return operations;
}
