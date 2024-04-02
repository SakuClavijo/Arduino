// Definición de pines
#define PIN_SENSOR_IZQUIERDO 2
#define PIN_SENSOR_DERECHO 3
#define PIN_MOTOR_IZQUIERDO_A 4
#define PIN_MOTOR_IZQUIERDO_B 5
#define PIN_MOTOR_DERECHO_A 6
#define PIN_MOTOR_DERECHO_B 7

// Variables
int valorSensorIzquierdo;
int valorSensorDerecho;

void setup() {
  // Inicializacion de pines
  pinMode(PIN_SENSOR_IZQUIERDO, INPUT);
  pinMode(PIN_SENSOR_DERECHO, INPUT);
  pinMode(PIN_MOTOR_IZQUIERDO_A, OUTPUT);
  pinMode(PIN_MOTOR_IZQUIERDO_B, OUTPUT);
  pinMode(PIN_MOTOR_DERECHO_A, OUTPUT);
  pinMode(PIN_MOTOR_DERECHO_B, OUTPUT);

  // Inicializacion del motor
  digitalWrite(PIN_MOTOR_IZQUIERDO_A, LOW);
  digitalWrite(PIN_MOTOR_IZQUIERDO_B, LOW);
  digitalWrite(PIN_MOTOR_DERECHO_A, LOW);
  digitalWrite(PIN_MOTOR_DERECHO_B, LOW);
}

void loop() {
  // Lectura de los sensores
  valorSensorIzquierdo = analogRead(PIN_SENSOR_IZQUIERDO);
  valorSensorDerecho = analogRead(PIN_SENSOR_DERECHO);

  // Control del robot
  // Control del robot
  if (valorSensorIzquierdo > valorSensorDerecho) {
    // Girar a la izquierda
    digitalWrite(PIN_MOTOR_IZQUIERDO_A, HIGH);
    digitalWrite(PIN_MOTOR_IZQUIERDO_B, LOW);
    digitalWrite(PIN_MOTOR_DERECHO_A, LOW);
    digitalWrite(PIN_MOTOR_DERECHO_B, HIGH);
  } else if (valorSensorIzquierdo < valorSensorDerecho) {
    // Girar a la derecha
    digitalWrite(PIN_MOTOR_IZQUIERDO_A, LOW);
    digitalWrite(PIN_MOTOR_IZQUIERDO_B, HIGH);
    digitalWrite(PIN_MOTOR_DERECHO_A, HIGH);
    digitalWrite(PIN_MOTOR_DERECHO_B, LOW);
  } else {
    // Avanzar
    digitalWrite(PIN_MOTOR_IZQUIERDO_A, HIGH);
    digitalWrite(PIN_MOTOR_IZQUIERDO_B, LOW);
    digitalWrite(PIN_MOTOR_DERECHO_A, HIGH);
    digitalWrite(PIN_MOTOR_DERECHO_B, LOW);
  }
  
}
