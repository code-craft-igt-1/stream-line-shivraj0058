#include <iostream>
#include <cstdlib>
#include "src/sender.h"

void sendVitalValue(const SensorStub& obj, double vitalminVal, double vitalmaxval) {
    double val=obj.generateRandomSensorValue(vitalminVal,vitalmaxval);
    std::cout<<val<<std::endl;
}

void sendVitalValues(){
    SensorStub obj;
    for(int i=0; i<50; i++) {
        sendVitalValue(obj,TEMPERATURE_LOWER_LIMIT,TEMPERATURE_UPPER_LIMIT);
        sendVitalValue(obj,PULSERATE_LOWER_LIMIT,PULSERATE_UPPER_LIMIT);
        sendVitalValue(obj,SPO2_LOWER_LIMIT,SPO2_UPPER_LIMIT);
    }
}
int main() {
    sendVitalValues();
    return 0;
}