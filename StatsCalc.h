#ifndef STATSCALC_H												// checks if StatsCalc has been defined
#define STATSCALC_H												// marks beginning of code

#include <vector>												// add neccessary header files
#include <string>

class StatsCalc {												// declaring class name
private:											
	std::vector<int> data;										//vector to store the data

public:
	void readFromFile(const std::string& filename);
	void calculateMean();
	void calculateStandardDeviation();
	void writeToOutputFile(const std::string& filename);
	double getMean();
	double getStandardDeviation();
};

#endif															// makes sure header is not used again