#include <Servo.h>

// Pinos dos componentes
const int pinLedVermelho = 9;
const int pinLedVerde = 8;
const int pinBotao = 2;
const int pinServo = 7;
const int pinBuzzer = 3;

Servo servoCancela;

void setup() {
  // Configurando pinos como saída ou entrada
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinBotao, INPUT);

  // Associando o pino ao servo motor
  servoCancela.attach(pinServo);

  // Ligando o LED vermelho inicialmente
  digitalWrite(pinLedVermelho, HIGH);
}

void loop() {
  // Verificando se o botão está pressionado
  if (digitalRead(pinBotao) == HIGH) {
    // Desliga o LED vermelho e liga o LED verde
    digitalWrite(pinLedVermelho, LOW);
    digitalWrite(pinLedVerde, HIGH);

    // Aciona o buzzer com um tom de 400 Hz por 100 milissegundos
    tone(pinBuzzer, 400);
    delay(100);
    noTone(pinBuzzer);

    // Move o servo para 90 graus
    servoCancela.write(90);

    // Aguardar 1 segundo
    delay(1000);

    // Retorna o servo para 0 graus após 1 segundo
    servoCancela.write(0);

    // Garantir que o buzzer esteja desligado
    noTone(pinBuzzer);

    // Desliga o LED verde e liga o LED vermelho
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedVermelho, HIGH);
  } else {
    // Mantém a cancela em 0 graus e o LED vermelho ligado
    servoCancela.write(0);
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedVermelho, HIGH);
    noTone(pinBuzzer);
  }
}
