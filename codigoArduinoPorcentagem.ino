// BLOCO DE DECLARAÇÃO
const int PINO_SENSOR_LDR = A0;
float valorLumi = 0;
float lumiPor = 0;

// BLOCO DE CONFIGURAÇÃO
void setup() {
  Serial.begin(9600);
}

//BLOCO DE EXECUÇÃO
void loop() {
  valorLumi = analogRead(PINO_SENSOR_LDR);

  lumiPor = valorLumi / 1023.0 * 100.0; // Transformando em porcentagem

  if (lumiPor < 0) lumiPor = 0; // Declarando limites das porcentagens
  if(lumiPor > 100) lumiPor = 100;

  // Declarando labels
  Serial.print("LumiMax:");
  Serial.print(80);
  Serial.print(" ");

  Serial.print("LumiAtual:");
  Serial.print(lumiPor);
  Serial.print(" ");

  Serial.print("LumiMin:");
  Serial.println(20);

  delay(500);
}
