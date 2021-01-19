// Copyright 2021 Pavlova D.
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <typename T>
class MyStack {
private:
  T *stack;
  unsigned int capacity;
  unsigned int top_el;

public:
  explicit MyStack(unsigned int new_capacity)
      : top_el(-1), capacity(new_capacity), stack(new T[new_capacity]) {}

  MyStack(const MyStack &old_stack) {
    this->capacity = old_stack.capacity;
    this->top_el = old_stack.top_el;
    this->stack = new T[old_stack.capacity];
    for (unsigned int i = 0; i < this->capacity; i++)
      this->stack[i] = old_stack.stack[i];
  }

  ~MyStack() {
    if (this->capacity > 0) {
      delete[] stack;
      this->capacity = 0;
      this->top_el = -1;
    }
  }

  T top() const {
    if (!this->isEmpty())
      return this->stack[this->top_el];
    else
      throw "Stack is empty";
  }

  T pop() {
    if (this->isEmpty())
      throw "Stack is empty";

    T tmp = this->stack[this->top_el];
    this->top_el--;

    return tmp;
  }

  void push(T elem) {
    if (this->isFull())
      throw "Stack is full";

    this->top_el++;
    this->stack[this->top_el] = elem;
  }

  bool isFull() const { return this->top_el == this->capacity - 1; }

  bool isEmpty() const { return this->top_el == -1; }
};

#endif // INCLUDE_MYSTACK_H_
