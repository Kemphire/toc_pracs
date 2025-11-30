#include "ques5.h"
#include <iostream>
#include <string>

void state1(std::string w, int i) {
  if (i == w.length()) {
    std::cout << "String accepted\n";
    return;
  }
  std::cout << "State1\n";

  if (w[i] == 'a') {
    state3(w, i + 1);
  } else if (w[i] == 'b') {
    state2(w, i + 1);
  }
}

void state2(std::string w, int i) {
  if (i == w.length()) {
    std::cout << "String rejected\n";
    return;
  }

  std::cout << "State2\n";

  if (w[i] == 'a') {
    state4(w, i + 1);
  } else if (w[i] == 'b') {
    state1(w, i + 1);
  }
}

void state3(std::string w, int i) {
  if (i == w.length()) {
    std::cout << "String rejected\n";
    return;
  }

  std::cout << "State3\n";

  if (w[i] == 'a') {
    state1(w, i + 1);
  } else if (w[i] == 'b') {
    state4(w, i + 1);
  }
}

void state4(std::string w, int i) {
  if (i == w.length()) {
    std::cout << "String rejected\n";
    return;
  }

  std::cout << "State4\n";

  if (w[i] == 'a') {
    state2(w, i + 1);
  } else if (w[i] == 'b') {
    state3(w, i + 1);
  }
}

int main() {

  std::string user_input;

  printf("Enter you desired string: ");

  std::cin >> user_input;

  state1(user_input, 0);
}
