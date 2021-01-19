// Copyright 2021 Pavlova D.
#include "postfix.h"
#include "MyStack.h"

int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}

std::string infix2postfix(std::string infix) {
  std::string rpn = {};
  MyStack<char> steck(100);

  for (int i = 0; i < (infix.length()); i++) {
    // 1
    if (infix[i] <= '9' && infix[i] >= '0' && infix[i + 1] != '0' &&
        infix[i + 1] != '1' && infix[i + 1] != '2' && infix[i + 1] != '3' &&
        infix[i + 1] != '4' && infix[i + 1] != '5' && infix[i + 1] != '6' &&
        infix[i + 1] != '7' && infix[i + 1] != '8' && infix[i + 1] != '9' &&
        infix[i + 1] != '.') {
      rpn += infix[i];
      rpn += " ";
    } else if (infix[i + 1] <= '9' && infix[i + 1] >= '0' && infix[i] <= '9' &&
                   infix[i] >= '0' ||
               infix[i + 1] == '.' || infix[i] == '.') {
      rpn += infix[i];
    } else if (infix[i] == ' ') {
      continue;
    } else if (infix[i] == ')')
    {
      while (steck.isEmpty() == 0 && steck.top() != '(') {
        auto op = steck.top();
        steck.pop();
        rpn += op;
        rpn += " ";
      }

      if (steck.top() == '(') {
        steck.pop();
      }
    } else if (infix[i] == '(') {
      steck.push('(');
    } else {
      while (steck.isEmpty() == 0 &&
             priority(steck.top()) >= priority(infix[i])) {
        auto op = steck.top();
        steck.pop();
        rpn += op;
        rpn += " ";
      }
      steck.push(infix[i]);
    }
  }

  while (steck.isEmpty() == 0) {
    auto op = steck.top();
    steck.pop();
    rpn += op;
    if (steck.isEmpty() == 0)
      rpn += " ";
  }

  return rpn;
}
