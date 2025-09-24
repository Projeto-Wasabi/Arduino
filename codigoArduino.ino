/* 
 *  LDR Lux Meter
 *  
 *  This sketch calculates the lux from a voltage reading
 *  
 *  The hardware connected to Analog Pin 0 should be a voltage divider circuit between an LDR and a 
 *  resistor (nominally 5kohm).  The resistor should be connected to ground and the LDR should be
 *  connected to 5V.  The point in between should be connected to Analog Pin 0.
 *  1) Calculate voltage based on reading
 *  2) Calculate resistance of LDR based on voltage
 *  3) Calculate the lux that must be falling on LDR based on the resistance
 *  
 *  The lux reading is then output to an Adafruit LCD shield.
 *  Created Dec. 4, 2015
 *  By David Williams
*/

// These constants, define values needed for the LDR readings and ADC
#define LDR_PIN                   0
#define MAX_ADC_READING           1023
#define ADC_REF_VOLTAGE           5.0
#define REF_RESISTANCE            5030  // measure this for best results
#define LUX_CALC_SCALAR           12518931
#define LUX_CALC_EXPONENT         -1.405

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/

void setup(void) 
{
  Serial.begin(9600);
}

/**************************************************************************/
void loop(void) 
{  
  
  int   ldrRawData;
  float resistorVoltage, ldrVoltage;
  float ldrResistance;
  float ldrLux;

  float lumiPor = 0;
  
  // Perform the analog to digital conversion  
  ldrRawData = analogRead(LDR_PIN);
  
  // RESISTOR VOLTAGE_CONVERSION
  // Convert the raw digital data back to the voltage that was measured on the analog pin
  resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;

  // voltage across the LDR is the 5V supply minus the 5k resistor voltage
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  
  // LDR_RESISTANCE_CONVERSION
  // resistance that the LDR would have for that voltage  
  ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE;
  
  // LDR_LUX
  // Change the code below to the proper conversion from ldrResistance to
  // ldrLux
  ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);

  lumiPor = ldrRawData / 1023.0 * 100.0; // Transformando em porcentagem
 
  Serial.println(""); 
  Serial.print(ldrLux);
  Serial.print(';');
  Serial.print(lumiPor);

  delay(1000);
}