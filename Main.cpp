#include "StatsCalc.h"
#include <iostream>

int main() {
	StatsCalc calculator;
	calculator.readFromFile("inMeanStd.dat");

	std::cout << "Data read from file 'inMeanStd.dat'" << std::endl;
	calculator.calculateMean();
	calculator.calculateStandardDeviation();
	calculator.writeToOutputFile("outMeanStd.dat");
}