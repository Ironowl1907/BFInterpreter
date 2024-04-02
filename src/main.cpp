#include <iostream>
#include <vector>
#include "../headers/interpreter.hpp"


int main (int argc, char *argv[]) {
  Interpreter interpreter;
  std::cout << 'a' << '\n';
  std::string input = "++>++";
  interpreter.Operate(input);
  return 0;
}
