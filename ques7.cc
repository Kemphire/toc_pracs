#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

void pop1(string input, int iter);
void pop2(string input, int iter);
void read1(string input, int iter);
void read2(string input, int iter);

stack<char> stack_storage;

void reject() { cout << "String Rejected\n"; }
void accept() { cout << "String Accepted"; }

void pop2(string input, int iter) {
  cout << "Input Pop2\n";
  if (stack_storage.empty()) {
    return accept();
  } else {
    return reject();
  }
}

void read2(string input, int iter) {
  cout << "Input Read2\n";
  try {
    if (input.at(iter) == 'b') {
      iter++;
      return pop1(input, iter);
    } else if (input.at(iter) == 'a') {
      return reject();
    }
  } catch (out_of_range &e) {
    iter++;
    return pop2(input, iter);
  }
}

void pop1(string input, int iter) {
  cout << "Input Pop1\n";

  if (stack_storage.empty()) {
    return reject();
  }
  auto top = stack_storage.top();
  stack_storage.pop();

  if (top == 'a') {
    return read2(input, iter);
  } else {
    return reject();
  }
}

void read1(string input, int iter) {
  cout << "Input Read1\n";
  try {
    if (input.at(iter) == 'a') {
      stack_storage.push(input.at(iter));
      iter++;
      return read1(input, iter);
    } else if (input.at(iter) == 'b') {
      iter++;
      return pop1(input, iter);
    }
  } catch (const out_of_range &e) {
    iter++;
    return pop2(input, iter);
  }
}

void start(string input) {
  cout << "Start\n";
  return read1(input, 0);
}

int main(int argc, char *argv[]) {
  cout << "Enter Your Inpt ";
  string input;
  cin >> input;

  cout << "Your Input " << input << "\n";
  start(input);
}
