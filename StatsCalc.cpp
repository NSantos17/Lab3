#include "StatsCalc.h"
#include <iostream>
#include <fstream>
#include <cmath>


void StatsCalc::readFromFile(const std::string& filename) {			// reads the data from file
	std::ifstream inputFile(filename);
	if (inputFile.is_open()) {
		int value;
		while (inputFile >> value) {
			data.push_back(value);
		}
		inputFile.close();
	}
}
void StatsCalc::calculateMean() {									// calculates mean
	int sum = 0;
	for (int value : data) {
		sum += value;
	}
	double mean = static_cast<double>(sum) / data.size();
	std::cout << "Mean: " << mean << std::endl;
}
void StatsCalc::calculateStandardDeviation() {						// calculates std deviation
	double mean = getMean();
	double variance = 0;
	for (int value : data) {
		variance += pow(value - mean, 2);
	}
	variance /= data.size();
	double stdDev = sqrt(variance);
	std::cout << "Standard Deviation: " << stdDev << std::endl;
}
void StatsCalc::writeToOutputFile(const std::string& filename) {	// writes std deviation and mean to output file
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
		outputFile << "Mean: " << getMean() << std::endl;
		outputFile << "Standard Deviation: " << getStandardDeviation() << std::endl;
		outputFile.close();
		std::cout << "Results written to " << filename << std::endl;
	}
}
double StatsCalc::getMean() {										// returns mean
	int sum = 0;
	for (int value : data) {
		sum += value;
	}
	return static_cast<double>(sum) / data.size();
}
double StatsCalc::getStandardDeviation() {							// returns std deviation
	double mean = getMean();
	double variance = 0;
	for (int value : data) {
		variance += pow(value - mean, 2);
	}
	variance /= data.size();
	return sqrt(variance);
}