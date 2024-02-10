#include "ComputePi.h"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std::chrono;

ComputePI::ComputePI(unsigned long long multiplier) {
  m_bn10 *= multiplier;

  auto r_size = 2ull * m_power10;
  auto decimals_size = m_bn10 / m_chunk;

  std::cout << " Building Pi Computer. " << r_size << std::endl;
  std::cout << "- r_size: " << r_size << std::endl;
  std::cout << "- decimals_size:" << (decimals_size * 9) << std::endl;

  m_r.resize(m_bn10, r_size);
  m_pi.resize(decimals_size, 0);
}

std::string formatDuration(auto totalSeconds) {
  auto hours = totalSeconds / 3600;
  auto minutes = (totalSeconds % 3600) / 60;
  auto seconds = totalSeconds % 60;

  std::ostringstream message;
  if (hours > 0) {
    message << hours << " hour" << (hours != 1 ? "s" : "");
  }
  if (minutes > 0) {
    if (!message.str().empty()) {
      message << ", ";
    }
    message << minutes << " minute" << (minutes != 1 ? "s" : "");
  }
  if (seconds > 0 ||
      message.str().empty()) { // Also add seconds if it's the only component
    if (!message.str().empty()) {
      message << ", ";
    }
    message << seconds << " second" << (seconds != 1 ? "s" : "");
  }

  return message.str();
}

void ComputePI::execute() {
  auto start = high_resolution_clock::now();
  LongInt index, k, b, d, c, ctr = 0ull;

  for (k = m_bn10; k > 0; k -= m_chunk) {
    std::cout << "K:  " << k << "\n";
    d = 0;
    
    for (auto index = k; index > 1; index--) {
      d += m_r[index] * m_power10;
      b = (2 * index) - 1;
      m_r[index] = d % b;
      d /= b;

      if (index > 1)
        d *= index;
    }

    m_pi[ctr] = c + (d / m_power10);

    c = d % m_power10;
    ctr++;
  }

  // After function call
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);

  // To get the value of duration use the count()
  // member function on the duration object
  std::cout << "\n PI computation time: " << formatDuration(duration.count())
            << "\n";
}

void ComputePI::writeFile() {
  FILE *pFile;
  pFile = fopen("pi.txt", "w");

  for (const auto &number : m_pi) {
    fprintf(pFile, "%09llu", number);
  }

  fclose(pFile);

  std::cout << "\n processed numbers count: " << m_r.size() << "\n";
  std::cout << "\n decimals count: " << m_pi.size() * 9 << "\n";
}
