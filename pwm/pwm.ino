#define LED 13

byte intensity = 0;
unsigned increment = 5;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(intensity);
  analogWrite(LED, intensity);

  if (intensity + increment > 255 || intensity + increment < 0) {
    increment = -increment;
  }

  intensity += increment;

  delay(50);
  
}
