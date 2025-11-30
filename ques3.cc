#include <iostream>

void our_fa(std::string w) {
  std::string start = w.substr(0, 2);
  std::string last = w.substr(w.size() - 2, 2);

  if (start == last) {
    printf("String Accepted");
  }
}

int main() {

  std::string user_input;

  printf("Enter you desired string: ");

  std::cin >> user_input;

  if (user_input.length() >= 4) {
    our_fa(user_input);
  }
}
