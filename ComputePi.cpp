#include "ComputePI.h"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std::chrono;

void ComputePI::execute()
{
	auto start = high_resolution_clock::now();

	LongInt index, k, b, d, c = 0ull;
	LongInt ctr = 0;
	for (k = bn10; k > 0; k -= 140)
	{
		d = 0;
		index = k;

		do
		{
			d += m_r[index] * power10;
			b = index + index - 1;
			m_r[index] = d % b;
			d /= b;

			if (index > 1)
				d *= index;

			index--;
		} while (index > 1);

		m_ds[ctr] = d;
		m_cs[ctr] = c;
		c = d % power10;
		ctr++;
	}

	// After function call
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);

	// To get the value of duration use the count()
	// member function on the duration object
	std::cout << "\n PI computation time: " << duration.count() << " seconds."
						<< std::endl;
}

void ComputePI::writeFile()
{
	FILE *pFile;
	pFile = fopen("/Users/mariano/code/EulerProject/pi.txt", "w");
	auto printCount = 0ull;

	for (auto i = 0ul; i < m_cs.size(); i++)
	{
		fprintf(pFile, "%.9llu", m_cs[i] + (m_ds[i] / power10));
		printCount++;
	}

	fclose(pFile);

	std::cout << "\n processed numbers count: " << m_r.size() << "\n";
	std::cout << "\n decimals count: " << printCount * log10(power10) << "\n";
}
