#include <wiringPi.h>
#include <stdio.h>
#include <stdbool.h>

// Define the pin numbers
const int motionDetectionPin = 4;  // GPIO pin for motion detection
const int ledPin = 18;  // GPIO pin for LED control

// Print message and control LED based on detection status
void printMessage(bool detected) {
    if (detected) {
        printf("Person detected ...\n");
    } else {
        printf("Person not detected ...\n");
    }

    // Control the LED based on the detection status
    digitalWrite(ledPin, detected ? HIGH : LOW);
}

int main(void) {
    // Initialize the wiringPi library
    if (wiringPiSetupGpio() == -1) {
        printf("Failed to initialize wiringPi\n");
        return -1;
    }

    // Set the pin modes
    pinMode(motionDetectionPin, INPUT);
    pinMode(ledPin, OUTPUT);

    // Infinite loop to detect a person around the device
    while (1) {
        // Check if a person is detected and set the detected flag
        bool detected = (digitalRead(motionDetectionPin) == HIGH);

        // Print the detection status and control the LED
        printMessage(detected);

        // Delay for 10 milliseconds
        delay(10);
    }

    return 0;
}
