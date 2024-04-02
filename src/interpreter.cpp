#include <string>
#include <iostream>
#include <vector>
#include "../headers/interpreter.hpp"

char Interpreter::at() { return buffer[pointer]; };


void Interpreter::Operate(std::string Instructions){
  pointer = 0;
  buffer = {0};
  index = 0;
  while (index < Instructions.size()) {
    // std::cout << "Iteration" << '\n';
    switch (Instructions[pointer]) {
      case '>': 
        pointer ++;
        if (pointer == buffer.size()) buffer.push_back(0);
        break;

      case '<':
        pointer --;
        if (pointer < 0){
          std::cout << "[Error] pointer addressed to a negative position" << '\n';
          return;
        }
        break;

      case '+':
        if ((int) at() == 255) buffer[pointer] = 0;
        else buffer[pointer] ++;
        break;

      case '-':
        if (at() == 0) buffer[pointer] = (char) 255;
        else buffer[pointer] --;
        break;

      case '.':
        std::cout << at();
          break;

      case ',':
        if (UserInput.empty()){
          std::string in;
          if (in == "") { std::cout << "[Error] No values recived" << '\n'; return; }
          std::getline(std::cin, in);
          UserInput += in; 
        }
        buffer[pointer] = UserInput[0];
        UserInput.erase(0,1);
        break;
    }
    index ++;
    for (auto a : buffer) {
      std::cout << (int) a << ' ';
    }
    std::cout << '\n';
  }
}
