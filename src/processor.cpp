#include "../include/processor.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<double> split(std::string str, std::string token) {
    std::vector<double> result;
    while (str.size()) {
        int index = str.find(token);
        if (index != std::string::npos) {
            result.push_back(std::stod(str.substr(0, index)));
            str = str.substr(index + token.size());
            if (str.size() == 0) result.push_back(std::stod(str));
        } else {
            result.push_back(std::stod(str));
            str = "";
        }
    }
    return result;
}
std::vector<double> readVitalValuesFromSenderAndProcess() {
    std::vector<double> vitalValues;
    for ( int i = 1; i <= 50; i++ ) {
        std::string vitals;
        std::cin >> vitals;
        vitalValues = split(vitals, ",");
        MaximumAndMinimumVitalValues(vitalValues);
        if (i%5 == 0)
            simpleMovingAverage(vitalValues);
    }
    return vitalValues;
}

void MaximumAndMinimumVitalValues(std::vector<double> vitalValues) {
    double maxTemperature = 0, minTemperature = 1000;
    double maxPulseRate = 0, minPulseRate = 1000;
    double maxSpo2 = 0, minSpo2 = 1000;
    for (int i = 0; i < vitalValues.size(); i += 3) {
        if (vitalValues[i] > maxTemperature) maxTemperature = vitalValues[i];
        if (vitalValues[i] < minTemperature) minTemperature = vitalValues[i];
        if (vitalValues[i + 1] > maxPulseRate) maxPulseRate = vitalValues[i + 1];
        if (vitalValues[i + 1] < minPulseRate) minPulseRate = vitalValues[i + 1];
        if (vitalValues[i + 2] > maxSpo2) maxSpo2 = vitalValues[i + 2];
        if (vitalValues[i + 2] < minSpo2) minSpo2 = vitalValues[i + 2];
    }
    std::cout << "Maximum and Minimum values of Temperature, Pulse Rate and Spo2 are: " << std::endl;
    std::cout << "Temperature: " << maxTemperature << " and " << minTemperature << std::endl;
    std::cout << "Pulse Rate: " << maxPulseRate << " and " << minPulseRate << std::endl;
    std::cout << "Spo2: " << maxSpo2 << " and " << minSpo2 << std::endl;
}

void simpleMovingAverage(std::vector<double> vitalValues)
{
    double sumTemperature = 0, sumPulseRate = 0, sumSpo2 = 0;
    for (int i = 0; i < vitalValues.size(); i += 3) {
        sumTemperature += vitalValues[i];
        sumPulseRate += vitalValues[i + 1];
        sumSpo2 += vitalValues[i + 2];
    }
    std::cout << "Simple Moving Average of Temperature, Pulse Rate and Spo2 are: " << std::endl;
    std::cout << "Temperature: " << sumTemperature / 5 << std::endl;
    std::cout << "Pulse Rate: " << sumPulseRate / 5 << std::endl;
    std::cout << "Spo2: " << sumSpo2 / 5 << std::endl;
}

int main() {
    readVitalValuesFromSenderAndProcess();
    return 0;
}
