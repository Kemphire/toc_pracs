#include "ques4.h"
#include <iostream>
#include <string>

void state4(std::string w, int i) {

  printf("State 4\n");

  if (i == w.length()) {
    printf("String is rejected\n");
    return;
  } else {
    if (w[i] == 'a' || w[i] == 'b') {
      state4(w, i + 1);
    }
  }
}

void state2(std::string w, int i) {

  printf("State 2\n");

  if (i == w.length()) {
    printf("String is rejected\n");
    return;
  } else {
    if (w[i] == 'a') {
      state2(w, i + 1);
    } else if (w[i] == 'b') {
      state3(w, i + 1);
    }
  }
}

void state3(std::string w, int i) {

  printf("State 2\n");

  if (i == w.length()) {
    printf("String is accepted\n");
    return;
  } else {
    if (w[i] == 'a') {
      state2(w, i + 1);
    } else if (w[i] == 'b') {
      state3(w, i + 1);
    }
  }
}

void state1(std::string w, int i) {
  printf("State 1\n");

  if (i == w.length()) {
    printf("String is rejected\n");
    return;
  } else {
    if (w[i] == 'a') {
      state2(w, i + 1);
    } else if (w[i] == 'b') {
      state4(w, i + 1);
    }
  }
}

int main(int argc, char *argv[]) {

  std::string user_input;

  printf("Enter you desired string: ");

  std::cin >> user_input;

  state1(user_input, 0);
}
