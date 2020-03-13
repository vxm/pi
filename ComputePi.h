#ifndef ComputePI_H
#define ComputePI_H

#include <vector>

class ComputePI
{
	using LongInt = unsigned long long;

	std::vector<LongInt> m_cs;
	std::vector<LongInt> m_ds;
	std::vector<LongInt> m_r;

	LongInt bn10 = 120ull * 5600ull;
	LongInt power10 = 1000000ul * 1000ul;

public:
	ComputePI(LongInt multiplier)
	{
		bn10 = multiplier * 5600ull;
		power10 = 100000ull * 10000ull;

		m_r.resize(bn10, 2ull * power10);
		m_cs.resize(bn10 / 140, 0);
		m_ds.resize(bn10 / 140, 0);
	}
	void execute();
	void writeFile();
};

#endif // ComputePI_H
