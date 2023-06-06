#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> firstList;
  std::map<int, std::string> secondList;
  std::string command;
  int count = 1;
  do {
    std::cout << "Enter 'last name' or command 'next' " << std::endl
              << "For print list enter < P > " << std::endl
              << "For exit enter < 0 >" << std::endl;
    std::cin >> command;
    if (command != "next" && command != "P") {
      firstList.insert(std::pair<std::string, int>(command, count));
      secondList.insert(std::pair<int, std::string>(count, command));
      count++;
    } else if (command == "next" && !secondList.empty()) {
      std::string lastname = firstList.begin()->first;
      std::cout << lastname << std::endl;
      if (lastname == secondList.begin()->second &&
          firstList.begin()->second == secondList.begin()->first) {
        firstList.erase(lastname);
        secondList.erase(secondList.begin()->first);
      } else {
        secondList.erase(secondList.begin()->first);
      }
    } else
      std::cout << "List is empty! or Enter error" << std::endl;
    if (command == "P" && !secondList.empty()) {
      for (auto &item : secondList)
        std::cout << item.first << " " << item.second << std::endl;
    }
  } while (command != "0");
  return 0;
}
