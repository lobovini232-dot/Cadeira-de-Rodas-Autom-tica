#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

// Pinos para controle de velocidade dos motores
#define ENA 10
#define ENB 11

void setup() {
  Serial.begin(9600);

  // Define os pinos dos motores como saídas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Velocidade dos motores (0 a 255)
  analogWrite(ENA, 110);
  analogWrite(ENB, 110);
}

char cha;

void loop() {
  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);

    // Movimenta para frente
    if (cha == 'F') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    // Movimenta para trás
    if (cha == 'B') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    // Movimenta para direita
    if (cha == 'R') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    // Movimenta para esquerda
    if (cha == 'L') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    // Para os motores
    if (cha == '0') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }
}