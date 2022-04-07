#include <iostream>
#include <string>
#include "CProblem.h"
#include "../methods/CMethod.h"

int main() {
  std::string massage;
  int* mass;
  int size;
  bool selected = 0;
  sortType type;

  size = 10 + rand() % 11;
  mass = new int[size];
  for (int i = 0; i < size; i++) {
    mass[i] = rand() % 101;
    std::cout << mass[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Enter the type of sort. Types available:" << std::endl;
  for (int i = 0; i < 3; i++) {
      switch (i){
      case (0):
              std::cout << "bubble" << std::endl;
      case(1):
          std::cout << "counting" << std::endl;
      case(2):
          std::cout << "quick" << std::endl;
      case(3):
          std::cout << "selections" << std::endl;
      }
  }
  CProblem problem(mass, size);
  do {
      switch (type) {
          problem.sort(selections);
          problem.print();
      }
  } while (selected != true);

  std::cout << std::endl;
  system("pause");
}
