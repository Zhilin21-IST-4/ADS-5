// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
T arr[100];
int left;

public:
TStack():left(-1) { }
T get() const {
return arr[left];
}
void pop() {
if (!isEmpty())
left--;
}
void push(T value) {
if (isFull())
throw "full";
else
arr[++left] = value;
}
bool isEmpty() const {
return left == -1;//пустота
}
bool isFull() const {
return left == size-1;//полнота
}
};
#endif  // INCLUDE_TSTACK_H_
