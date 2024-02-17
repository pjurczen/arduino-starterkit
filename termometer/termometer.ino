const int sensorPin = A0;
const float baselineTemp = 23.9;


void setup() {
    Serial.begin(9600);
    for(int pin=2; pin < 5; pin++) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }    
}

void loop() {
    int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor value: " + String(sensorVal));
    float voltage = (sensorVal/1024.0) * 5.0;
    Serial.print(", Voltage: " + String(voltage));
    float temperature = (voltage - 0.5) * 100;
    Serial.println(", Degrees C: " + String(temperature));
    if (temperature < baselineTemp + 2) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp + 6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(500);
}