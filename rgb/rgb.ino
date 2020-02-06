#define R 13
#define V 12
#define B 11

short increment = 255;
unsigned rgbMax = 256 * 256 * 256;
unsigned rgb = 0;

void setup() {
  
  pinMode(R, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(B, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  byte red = (rgb >> 16) & 0xff;
  byte green = (rgb >> 8) & 0xff;
  byte blue = rgb & 0xff;
  Serial.print("R: "); 
  Serial.print(red);
  Serial.print(" V: "); 
  Serial.print(green);
  Serial.print(" B: "); 
  Serial.println(blue);
  
  analogWrite(R, red);
  analogWrite(V, green);
  analogWrite(B, blue);
  
  if (rgb + increment > rgbMax || rgb + increment < 0) {
    increment = -increment;
  }

  rgb += increment;
}
