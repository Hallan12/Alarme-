// C++ code
//
const int trigPin = 3;
const int echoPin = 2;
const int buzzerPin = 8;
const int led = 12;
void setup()
{
Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
long duracao;
float distancia;

 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duracao = pulseIn(echoPin, HIGH);
  
  distancia = duracao * 0.034/2;
  
  Serial.print("Distância:");
  Serial.print(distancia);
  Serial.println("em CM");
  if(distancia <15) {
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
}
  
  
  delay(300);
}