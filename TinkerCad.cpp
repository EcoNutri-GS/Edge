#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int tempoDelay = 5000;

int tempSensorPin = A0; // pino do sensor de temperatura
int lightSensorPin = A1; // pino do sensor de umidade
int potPin = A2; // pino do potenciômetro
int motorPin = 13; // pino do motor
int  interruptorCarne = 0;
int  interruptorHortalicas = 0;
int  interruptorLaticinios = 0;
int  interruptorCongelados = 0;
int motorEstado = 0;
bool interruptorLigado = true; // Estado do interruptor
float luzBaixa = 0;
float luzAlta = 0;
float umidadeBaixa = 0;
float umidadeAlta = 0;
float temperaturaAlta = 0;
float temperaturaBaixa = 0;
String telaArmazem = "";



void setup()
{
  lcd.begin(16, 2);
  lcd.print("INICIALIZANDO");
  lcd.setCursor(0, 1);
  lcd.print("SISTEMA!");
  delay(3000);
  lcd.clear();
  lcd.print("Aguarde...");
  delay(3000);
  lcd.clear();

  pinMode(tempSensorPin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(9, INPUT); // Pino do interruptor
  pinMode(1, INPUT); // Pino da Carne
  pinMode(6, INPUT); // Pino da Legumes, verduras e frutas
  pinMode(7, INPUT); // Pino da Laticinios
  pinMode(8, INPUT); // Pino da Congelados
  pinMode(motorPin, OUTPUT); // Pino do motor
 
  Serial.begin(9600);
  
  digitalWrite(1, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}

void loop()
{
  // Ler o estado do interruptor
  bool estadoInterruptor = digitalRead(9);

  // Atualizar o estado do interruptor
  interruptorLigado = (estadoInterruptor == HIGH);
  
  interruptorCarne = digitalRead(1);
  interruptorHortalicas = digitalRead(6);
  interruptorLaticinios = digitalRead(7);
  interruptorCongelados = digitalRead(8);
  motorEstado = digitalRead(motorPin);
  if (interruptorCarne==HIGH) {
    umidadeAlta = 0.90;
    umidadeBaixa = 0.85;
    temperaturaAlta = 4;
    temperaturaBaixa = 0;
    telaArmazem = "CARNE";
  } else if (interruptorHortalicas==HIGH) {
    umidadeAlta = 0.95;
    umidadeBaixa = 0.90;
    temperaturaAlta = 10;
    temperaturaBaixa = 2; 
    telaArmazem = "HORTALIÇAS";
  } else if (interruptorLaticinios==HIGH)  {
    umidadeAlta = 0.95;
    umidadeBaixa = 0.75;
    temperaturaAlta = 7;
    temperaturaBaixa = -5;  
    telaArmazem = "LATICINIOS";
  } else if (interruptorCongelados==HIGH) {
    umidadeAlta = 0.95;
    umidadeBaixa = 0.75;
    temperaturaAlta = -10;
    temperaturaBaixa = -12; 
    telaArmazem = "CONGELADOS"; 
  } else {
    umidadeAlta = 0;
    umidadeBaixa = 0;
    temperaturaAlta = 0;
    temperaturaBaixa = 0; 
    telaArmazem = " ? "; 
  }
  

  if (interruptorLigado) {
    lcd.setCursor(0, 0);
    lcd.print("ARMAZENANDO");
    lcd.setCursor(0, 1);
    lcd.print(telaArmazem);
    delay(tempoDelay);
    lcd.clear();
    
    // ler os valores dos sensores
    float tempLido = analogRead(tempSensorPin); // convertendo para Celsius
    float tempC = ((tempLido * (5.0 / 1023.0)) - 0.5) * 100.0;
    int lightValue = analogRead(lightSensorPin);
    int potValue = analogRead(potPin);

    if (potValue < 100)
    {
      potValue = 100;
    }
    else if (potValue > 900)
    {
      potValue = 900;
    }

    int brightness = map(potValue, 100, 900, 0, 255);

    if (lightValue < 1023 * umidadeBaixa)
    {
      lcd.setCursor(0, 0);
      lcd.print("AVISO!Umid.BAIXA");
      lcd.setCursor(0, 1);
      lcd.print("Umidade = ");
      lcd.print((lightValue) / 10);
      lcd.print("%");
      
      delay(1500);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("LIGANDO");
      lcd.setCursor(0, 1);
      lcd.print("UMIDIFICADORES");
      digitalWrite(motorPin, HIGH);
    }
    else if (lightValue >= 1023 * umidadeBaixa && lightValue <= 1023 * umidadeAlta)
    {
      lcd.setCursor(0, 0);
      lcd.print("Umidade IDEAL");
      lcd.setCursor(0, 1);
      lcd.print("Umidade = ");
      lcd.print((lightValue) / 10);
      lcd.print("%");
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("AVISO!Umid.ALTA");
      lcd.setCursor(0, 1);
      lcd.print("Umidade = ");
      lcd.print((lightValue) / 10);
      lcd.print("%");
            
      delay(1500);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("DESLIGANDO");
      lcd.setCursor(0, 1);
      lcd.print("UMIDIFICADORES");
      digitalWrite(motorPin, LOW);
    }

    delay(tempoDelay);
    lcd.clear();
    digitalWrite(motorPin, LOW);

    if (tempC >= temperaturaBaixa && tempC <= temperaturaAlta)
    {
      lcd.setCursor(0, 0);
      lcd.print("Temp. IDEAL");
      lcd.setCursor(0, 1);
      lcd.print("Temp. = ");
      lcd.print(tempC, 1);
      lcd.print("C");
    }
    else if (tempC > temperaturaAlta)
    {
      lcd.setCursor(0, 0);
      lcd.print("AVISO!Temp.ALTA");
      lcd.setCursor(0, 1);
      lcd.print("Temp. = ");
      lcd.print(tempC, 1);
      lcd.print("C");
                  
      delay(1500);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("LIGANDO");
      lcd.setCursor(0, 1);
      lcd.print("REFRIGERADORES");
      digitalWrite(motorPin, HIGH);
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("AVISO!Temp.BAIXA");
      lcd.setCursor(0, 1);
      lcd.print("Temp. = ");
      lcd.print(tempC, 1);
      lcd.print("C");
                        
      delay(1500);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("DESLIGANDO");
      lcd.setCursor(0, 1);
      lcd.print("REFRIGERADORES");  
    }

    delay(tempoDelay);
    lcd.clear();
    digitalWrite(motorPin, LOW);
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("SISTEMA ");
    lcd.setCursor(0, 1);
    lcd.print("DESLIGADO");
    delay(tempoDelay);
    lcd.clear();
  }
}
