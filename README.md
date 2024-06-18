# Sensor de Proximidade para Carros da Formula E

## Descrição

Este projeto consiste em um sistema de sensores de proximidade para carros de Formula E, com o objetivo de evitar acidentes laterais e traseiros causados por pontos cegos. Utilizando sensores de distância (HC-SR04) e LEDs para alertar o piloto sobre a proximidade de outros carros, o sistema pisca LEDs vermelhos ou laranjas dependendo da distância medida.


## Membros do grupo


557356 – Alex Ribeiro​

556030 – Caio Venancio​

557538 – David Cordeiro​

556228 – Marcos Henrique​

555619 – Tiago Morais

## Funcionalidades

- Cada sensor cuida de um lado do carro com um possível ponto cego.
- Há um sensor na direita, um na esquerda e um na parte traseira do carro.
- De acordo com o nível de proximidade, uma luz vermelha ou laranja pisca para o piloto.
  - Se a distância for menor que 1 metro, a luz vermelha pisca.
  - Se a distância estiver entre 1 e 2 metros, a luz laranja pisca.
- Os sensores são utilizados para evitar colisões laterais e traseiras, especialmente em pontos cegos.

## Exibição via Wokwi

Abaixo está sendo exibido uma captura de tela do projeto sendo apresentado via Wokwi

![Screenshot_1](https://github.com/davidcordeiro15/Sprint_1_Edge/assets/161903325/31ada953-e4f1-4002-94ad-10526ec7bfa2)

![Screenshot_2](https://github.com/davidcordeiro15/Sprint_1_Edge/assets/161903325/b95a0d4f-b122-48aa-9d42-28bd300cdbb0)


## Materiais

- 1 Arduino UNO
- 1 Breadboard
- 3 Sensores de Distância (HC-SR04)
- 3 LEDs Vermelhos
- 3 LEDs Laranjas
- 6 Resistores de 1k Ohms
- Fios

## Circuito

### Ligações dos Sensores

- **Sensor da Esquerda:**
  - TRIG_PIN_E -> Pino 3
  - ECHO_PIN_E -> Pino 2

- **Sensor do Meio:**
  - TRIG_PIN_M -> Pino 5
  - ECHO_PIN_M -> Pino 4

- **Sensor da Direita:**
  - TRIG_PIN_D -> Pino 9
  - ECHO_PIN_D -> Pino 8

### Ligações dos LEDs

- **LEDs da Esquerda:**
  - LED Vermelho -> Pino 10
  - LED Laranja -> Pino 11

- **LEDs do Meio:**
  - LED Vermelho -> Pino 13
  - LED Laranja -> Pino 12

- **LEDs da Direita:**
  - LED Vermelho -> Pino 7
  - LED Laranja -> Pino 6

## Como Usar
Conecte os sensores de distância e os LEDs conforme as instruções acima.
Carregue o código no Arduino UNO usando a IDE do Arduino.
Abra o Serial Monitor para visualizar as distâncias medidas pelos sensores.
Observe os LEDs piscando conforme a proximidade de objetos detectada pelos sensores.

##Link do projeto no Wokwi
https://wokwi.com/projects/399046271463787521

## Licença
Este projeto é de código aberto e pode ser utilizado livremente para fins educacionais e pessoais.
