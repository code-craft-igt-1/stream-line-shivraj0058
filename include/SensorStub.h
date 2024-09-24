
#include <iostream>
#include <cstdlib>
#include <ctime>

class SensorStub {
public:
    SensorStub() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    double generateRandomSensorValue (double minValue, double maxValue) const {
        double f = static_cast<double>(std::rand()) / RAND_MAX;
        return minValue + f * (maxValue - minValue);
    }
};


#include <gtest/gtest.h>
#include "SensorStub.h"

TEST(SensorStubTest, GenerateRandomSensorValue) {
    SensorStub sensor;

    // Test case 1: minValue = 0, maxValue = 10
    double minValue1 = 0.0;
    double maxValue1 = 10.0;
    double value1 = sensor.generateRandomSensorValue(minValue1, maxValue1);
    EXPECT_GE(value1, minValue1);
    EXPECT_LE(value1, maxValue1);

    // Test case 2: minValue = -5, maxValue = 5
    double minValue2 = -5.0;
    double maxValue2 = 5.0;
    double value2 = sensor.generateRandomSensorValue(minValue2, maxValue2);
    EXPECT_GE(value2, minValue2);
    EXPECT_LE(value2, maxValue2);

    // Add more test cases as needed
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}