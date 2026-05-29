// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };

    int operations;   // количество выполненных переходов
    Car* head;        // указатель на начало состава
    Car* now;         // позиция текущего вагона

    void resetCounter() { operations = 0; }
    void moveForward();
    void moveBackward();

 public:
    Train();
    ~Train();
    void addCar(bool light);
    int getLength();
    int getOpCount() const;
};

#endif // INCLUDE_TRAIN_H_
