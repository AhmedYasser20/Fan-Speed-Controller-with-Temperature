#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include <util/delay.h>
#include "adc.h"
#include "gpio.h"

typedef enum {
    OFF,  // Fan is off
    ON    // Fan is on
} FanState;

void main(void) {
    // Configuration for Analog-to-Digital Converter (ADC)
    ADC_ConfigType ADC_PTR = {Internal_volt_2_56, Prescaler_8};

    // Initialize the LCD display
    LCD_init();

    // Initialize the DC motor
    DcMotor_Init();

    // Initialize the Analog-to-Digital Converter (ADC)
    ADC_init(&ADC_PTR);

    // Display initial messages on the LCD
    LCD_displayStringRowColumn(0, 4, "FAN IS ");
    LCD_displayStringRowColumn(1, 4, "TEMP =    C");

    FanState State = OFF;  // Initialize the fan state to OFF
    uint8 Temp = 0;  // Initialize temperature variable

    while (1) {
        // Read the temperature from LM35 temperature sensor
        Temp = LM35_getTemperature();

        // Rotate the DC motor in a specific direction and speed based on temperature
        DcMotor_Rotate(State_ClockWise, 64);

        // Check the temperature and control the fan accordingly
        if (Temp < 30) {
            State = OFF;
            DcMotor_Rotate(State_Stop, 0);  // Stop the fan
        } else if (Temp >= 30 && Temp < 60) {
            State = ON;
            DcMotor_Rotate(State_ClockWise, 64);  // Rotate the fan at a slow speed
        } else if (Temp >= 60 && Temp < 90) {
            State = ON;
            DcMotor_Rotate(State_ClockWise, 128);  // Rotate the fan at a medium speed
        } else if (Temp >= 90 && Temp < 120) {
            State = ON;
            DcMotor_Rotate(State_ClockWise, 128 + 64);  // Rotate the fan at a higher speed
        } else {
            State = ON;
            DcMotor_Rotate(State_ClockWise, 255);  // Rotate the fan at the highest speed
        }

        // Update the fan state on the LCD display
        if (State) {
            LCD_displayStringRowColumn(0, 11, " ON ");
        } else {
            LCD_displayStringRowColumn(0, 11, " OFF");
        }

        // Reset Cursor
        LCD_moveCursor(1, 10);

        // Check if the temperature is greater than or equal to 100 for proper formatting
        if (Temp >= 100) {
            LCD_intgerToString(Temp);  // Display the temperature
        } else {
            LCD_intgerToString(Temp);  // Display the temperature
            LCD_displayString(" ");  // Add a space for proper alignment
        }
    }
}
