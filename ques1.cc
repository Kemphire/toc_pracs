#include <iostream>
#include <string>

using namespace std;

void State1(string w, int i);
void State2(string w, int i);
void State3(string w, int i);

int main() {
  string w;
  cout << "Enter a string: ";
  cin >> w;
  State1(w, 0);
  return 0;
}

void State1(string w, int i) {
  cout << "State 1" << endl;
  if (i == w.length()) {
    cout << "String is accepted" << endl;
    return;
  } else {
    if (w[i] == 'b') {
      State1(w, i + 1);
    } else if (w[i] == 'a') {
      State2(w, i + 1);
    }
  }
}

void State2(string w, int i) {
  cout << "State 2" << endl;
  if (i == w.length()) {
    cout << "String is accepted" << endl;
    return;
  } else {
    if (w[i] == 'b') {
      State1(w, i + 1);
    } else if (w[i] == 'a') {
      State3(w, i + 1);
    }
  }
}

void State3(string w, int i) {
  cout << "State 3" << endl;
  if (i == w.length()) {
    cout << "String is rejected" << endl;
    return;
  } else {
    if (w[i] == 'b' || w[i] == 'a') {
      State3(w, i + 1);
    }
  }
}
