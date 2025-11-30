#include <iostream>
#include <string>

void State5(std::string w, int i) {

  printf("State 4\n");

  if (i == w.length()) {
    printf("String is accepted\n");
    return;
  } else {
    if (w[i] == '0' || w[i] == 1) {
      State5(w, i + 1);
    }
  }
}

void State4(std::string w, int i) {
  printf("State 4\n");

  if (i == w.length()) {
    printf("String is accepted\n");
    return;
  } else {
    if (w[i] == '0') {
      State4(w, i + 1);
    } else if (w[i] == '1') {
      State5(w, i + 1);
    }
  }
}

void State3(std::string w, int i) {

  printf("State 3\n");

  if (i == w.length()) {
    printf("String is accepted\n");
    return;
  } else {
    if (w[i] == '0') {
      State3(w, i + 1);
    } else if (w[i] == '1') {
      State4(w, i + 1);
    }
  }
}

void State2(std::string w, int i) {

  printf("State 2\n");

  if (i == w.length()) {
    printf("String is accepted\n");
    return;
  } else {
    if (w[i] == '0') {
      State2(w, i + 1);
    } else if (w[i] == '1') {
      State3(w, i + 1);
    }
  }
}

void state1(std::string w, int i) {
  printf("State 1\n");

  if (i == w.length()) {
    printf("String is accepted\n");
    return;
  } else {
    if (w[i] == '0') {
      state1(w, i + 1);
    } else if (w[i] == '1') {
      State2(w, i + 1);
    }
  }
}

int main(int argc, char *argv[]) {

  std::string user_input;

  printf("Enter you desired string: ");

  std::cin >> user_input;

  state1(user_input, 0);
}
