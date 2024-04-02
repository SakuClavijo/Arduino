#define PIN_SENSOR_LINEA_IZQUIERDA 2
#define PIN_SENSOR_LINEA_DERECHA 3
#define PIN_MOTOR_IZQUIERDO_ADELANTE 4
#define PIN_MOTOR_IZQUIERDO_ATRAS 5
#define PIN_MOTOR_DERECHO_ADELANTE 6
#define PIN_MOTOR_DERECHO_ATRAS 7


int valorSensorIzquierdo;
int valorSensorDerecho;
int velocidadMotor = 255; // Ajustar la velocidad del robot


void setup() {
  // Inicialización de pines como entradas/salidas
  pinMode(PIN_SENSOR_LINEA_IZQUIERDA, INPUT);
  pinMode(PIN_SENSOR_LINEA_DERECHA, INPUT);
  pinMode(PIN_MOTOR_IZQUIERDO_ADELANTE, OUTPUT);
  pinMode(PIN_MOTOR_IZQUIERDO_ATRAS, OUTPUT);
  pinMode(PIN_MOTOR_DERECHO_ADELANTE, OUTPUT);
  pinMode(PIN_MOTOR_DERECHO_ATRAS, OUTPUT);

  // Inicialización del motor en estado de reposo
  digitalWrite(PIN_MOTOR_IZQUIERDO_ADELANTE, LOW);
  digitalWrite(PIN_MOTOR_IZQUIERDO_ATRAS, LOW);
  digitalWrite(PIN_MOTOR_DERECHO_ADELANTE, LOW);
  digitalWrite(PIN_MOTOR_DERECHO_ATRAS, LOW);
}


void loop() {
  // Lectura de los sensores
  valorSensorIzquierdo = analogRead(PIN_SENSOR_LINEA_IZQUIERDA);
  valorSensorDerecho = analogRead(PIN_SENSOR_LINEA_DERECHA);

  // Control del robot
  if (valorSensorIzquierdo > valorSensorDerecho) {
    // Girar a la izquierda
    digitalWrite(PIN_MOTOR_IZQUIERDO_ADELANTE, LOW);
    digitalWrite(PIN_MOTOR_IZQUIERDO_ATRAS, HIGH);
    digitalWrite(PIN_MOTOR_DERECHO_ADELANTE, HIGH);
    digitalWrite(PIN_MOTOR_DERECHO_ATRAS, LOW);
  } else if (valorSensorIzquierdo < valorSensorDerecho) {
    // Girar a la derecha
    digitalWrite(PIN_MOTOR_IZQUIERDO_ADELANTE, HIGH);
    digitalWrite(PIN_MOTOR_IZQUIERDO_ATRAS, LOW);
    digitalWrite(PIN_MOTOR_DERECHO_ADELANTE, LOW);
    digitalWrite(PIN_MOTOR_DERECHO_ATRAS, HIGH);
  } else {
    // Avanzar en línea recta
    digitalWrite(PIN_MOTOR_IZQUIERDO_ADELANTE, HIGH);
    digitalWrite(PIN_MOTOR_IZQUIERDO_ATRAS, LOW);
    digitalWrite(PIN_MOTOR_DERECHO_ADELANTE, HIGH);
    digitalWrite(PIN_MOTOR_DERECHO_ATRAS, LOW);
  }

  // Detección de obstáculos (pendiente)
  // ...

  // Interfaz de usuario (pendiente)
  // ...
}
