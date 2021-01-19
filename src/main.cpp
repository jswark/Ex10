// Copyright 2021 Pavlova D.
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
  std::string s1("2 + 6 * 3 / (4 - 2)");
  std::cout << "Infix : " << s1 << std::endl;
  std::string s1_post = infix2postfix(s1);
  std::cout << "RPN : " << s1_post << std::endl;  // 2 6 3 * 4 2 - / +

  std::string s2 = "1 + 2.3 - 10 + (55 - 15 + 25 * 4.3) * 10";
  std::cout << "Infix : " << s2 << std::endl;
  std::string s2_post = infix2postfix(s2);
  std::cout << "PRN : " << s2_post
            << std::endl;  // 1 2.3 + 10 - 55 15 - 25 4.3 * + 10 * +
  return 0;
}
