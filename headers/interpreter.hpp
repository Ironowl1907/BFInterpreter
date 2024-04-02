#pragma once

class Interpreter{
  private:
  std::vector<char> buffer = {0};
  unsigned int pointer = 0;
  std::string UserInput = "";
  unsigned int index = 0;

  private:
  char at();

  public:
  void Operate(std::string Instructions);
};
