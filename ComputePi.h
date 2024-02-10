#ifndef ComputePI_H
#define ComputePI_H

#include <vector>

class ComputePI {
  using LongInt = unsigned long long;

  std::vector<LongInt> m_pi;
  std::vector<LongInt> m_r;

  LongInt m_bn10 = 672000ull;
  constexpr static const LongInt m_chunk = 140ull;
  LongInt m_power10 = 1000000000ull;

public:
  ComputePI(unsigned long long multiplier);
  void execute();
  void writeFile();
};

#endif // ComputePI_H