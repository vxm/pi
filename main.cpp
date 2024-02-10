#include "ComputePi.h"
#include <charconv>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>

std::optional<int> convertToInt(char *arg) {
  int value = 0;
  auto [ptr, ec] = std::from_chars(arg, arg + std::strlen(arg), value);
  if (ec == std::errc()) {
    return value;
  }
  return std::nullopt;
}

int main(int argc, char *argv[]) {
  std::optional<int> intArgument;
  if (argc > 1) {
    intArgument = convertToInt(argv[1]);
  }

  if (intArgument.has_value()) {
    ComputePI computer((unsigned long long) intArgument.value());
    computer.execute();
    computer.writeFile();
    std::cout << "-- Pi written to file with multiplier: " << (argv[1]) << '\n';
  } else {
    std::cout << "Multiplier not provided its type was not of Integer."
              << std::endl;
  }

  return 0;
}