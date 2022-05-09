// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
        T arr[100];
        int top1;

 public:
    TStack(): top1(-1) { }
    T get() const {
      return arr[top1];
    }
    bool isEmpty() const {
      return top1 == -1;
    }
    bool isFull() const {
      return top1 == size - 1;
    }
    void pop() {
      if (top1 >= 0)
        top1--;
      }
    void push(T item) {
       if (top1 < size - 1)
         arr[++top1] = item;
       }
};
#endif  // INCLUDE_TSTACK_H_
