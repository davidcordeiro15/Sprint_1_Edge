/*
      Sprint 1 
 Sensor de proximidade para carros da Formula E

Funções:
- Cada sensor cuida de um lado do carro com um possível ponto cego.
- Um sensor na direita, um na esquerda e um atrás no meio.
- De acordo com o nível de proximidade uma luz vermelha ou laranja pisca para o piloto.
- Se a distância for menor do que 1m a luz vermelha pisca.
- Caso a distância com o outro carro for entre 2m e 1m uma luz laranja pisca.
- Os sensores são utilizados afim de evitar acidentes em que ocorrem batisdas laterais por conta de pontos cegos, ou batidas traseiras.

Materiais:
- Arduino UNO;
- Breadboard;
- 3 sensores de distância (HC-SR04);
- 3 led's vermelhos; 
- 3 led's laranjas;
- 6 resistores de 1 kilo ohm's;
- Fios.

*/

//Sensor da esquerda
#define ECHO_PIN_E 2
#define TRIG_PIN_E 3

//sensor do meio
#define ECHO_PIN_M 4
#define TRIG_PIN_M 5

//sensor da direita
#define ECHO_PIN_D 8
#define TRIG_PIN_D 9

//led's da esquerda
const int ledR_E = 10;
const int ledO_E = 11;

//led's do meio
const int ledR_M = 13;
const int ledO_M = 12;

//led's da direita
const int ledR_D = 7;
const int ledO_D = 6;


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN_E, OUTPUT);
  pinMode(ECHO_PIN_E, INPUT);
  pinMode(TRIG_PIN_M, OUTPUT);
  pinMode(ECHO_PIN_M, INPUT);
  pinMode(TRIG_PIN_D, OUTPUT);
  pinMode(ECHO_PIN_D, INPUT);
  pinMode(ledR_E, OUTPUT);
  pinMode(ledO_E, OUTPUT);

}

//Criando a função para medição dos dados da esquerda
double readDistanceCM_E() {
  digitalWrite(TRIG_PIN_E, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_E, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_E, LOW);
  int duration_E = pulseIn(ECHO_PIN_E, HIGH);
  return duration_E * 0.034 / 2;
}

//Criando a função para medição dos dados do meio
double readDistanceCM_M() {
  digitalWrite(TRIG_PIN_M, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_M, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_M, LOW);
  int duration_M = pulseIn(ECHO_PIN_M, HIGH);
  return duration_M * 0.034 / 2;
}

//Criando a função para medição dos dados da direita
double readDistanceCM_D() {
  digitalWrite(TRIG_PIN_D, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_D, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_D, LOW);
  int duration_D = pulseIn(ECHO_PIN_D, HIGH);
  return duration_D * 0.034 / 2;
}

void loop() {

  double esquerda = readDistanceCM_E();
  double direita = readDistanceCM_D();
  double meio = readDistanceCM_M();

  //comparando os dados para acender ou não os led's
  if (esquerda <= 100.0) {
    digitalWrite(ledR_E, HIGH);
    delay(100);
    digitalWrite(ledR_E, LOW);
  } else if (esquerda > 100.0 && esquerda <=200.0) {
    digitalWrite(ledO_E, HIGH);
    delay(100);
    digitalWrite(ledO_E, LOW);
  }
  if (direita <= 100.0) {
    digitalWrite(ledR_D, HIGH);
    delay(100);
    digitalWrite(ledR_D, LOW);
  } else if (direita > 100.0 && direita <=200.0) {
    digitalWrite(ledO_D, HIGH);
    delay(100);
    digitalWrite(ledO_D, LOW);
  } 
  if (meio <= 100.0) {
  digitalWrite(ledR_M, HIGH);
  delay(100);
  digitalWrite(ledR_M, LOW);
  } else if (meio > 100.0 && meio <=200.0) {
  digitalWrite(ledO_M, HIGH);
  delay(100);
  digitalWrite(ledO_M, LOW);
  }

  Serial.println(esquerda);
  Serial.print("Distância na esquerda: ");
  Serial.println(readDistanceCM_E());
  Serial.print("Distância no meio: ");
  Serial.println(readDistanceCM_M());
  Serial.print("Distância na direita: ");
  Serial.println(readDistanceCM_D());

  delay(100);
}
