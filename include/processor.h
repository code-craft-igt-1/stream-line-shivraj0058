#pragma once

#include <vector>

std::vector<double> readVitalValuesFromSender();
void MaximumAndMinimumVitalValues(std::vector<double> vitalValues);
void simpleMovingAverage(std::vector<double> vitalValues);