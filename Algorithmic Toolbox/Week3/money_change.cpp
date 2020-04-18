#include <iostream>

int get_change(int m) {
  int n = 0;
  while (m >= 10) {
      m -= 10;
      n++;
  }
  while (m >= 5) {
      m -= 5;
      n++;
  }

  return n + m;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
