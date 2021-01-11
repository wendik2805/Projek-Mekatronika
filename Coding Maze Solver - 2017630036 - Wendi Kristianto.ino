#define trigPin1 10
#define echoPin1 11
#define trigPin2 12
#define echoPin2 13
#define trigPin3 8
#define echoPin3 2

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;

const int kiri = 0;
const int depan = 1;
const int kanan = 2;

const int utara = 0;
const int timur = 1;
const int selatan = 2;
const int barat = 3;

const int panjang_cell = 5;
const int lebar_cell = 5;
const int x_fin = 2;
const int y_fin = 2;

int x_cor , y_cor;
int hadap;

long duration, distance, RightSensor, FrontSensor, LeftSensor;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  x_cor = 0;
  y_cor = 4;
  hadap = selatan;
}

void loop() {
  if (x_cor== x_fin && y_cor == y_fin){
  delay(100000);
}
else{
  delay(3000);
  SonarSensor(trigPin2, echoPin2);
  RightSensor = distance;
  SonarSensor(trigPin3, echoPin3);
  FrontSensor = distance;
  SonarSensor(trigPin1, echoPin1);
  LeftSensor = distance;

  Serial.print(LeftSensor);
  Serial.print(" - ");
  Serial.print(FrontSensor);
  Serial.print(" - ");
  Serial.println(RightSensor);

  if (LeftSensor > 5) {
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(225);
    if(hadap == utara){
    hadap = barat;
  }
  else if (hadap == barat){
     hadap = selatan;
  }
  else if (hadap == selatan){
    hadap = timur;
  }
  else if (hadap == timur){
    hadap = utara;
  }
    analogWrite(ENA, 200);
    analogWrite(ENB, 165);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(460);
 if (hadap == utara){
    y_cor++;
  }
  else if(hadap == timur){
    x_cor++;
  }
  else if(hadap == selatan){
    y_cor--;
  }
  else if(hadap == barat){
    x_cor--;
  }
  }
  else if (FrontSensor > 5) { //---------MAJU-------------
    analogWrite(ENA, 200);
    analogWrite(ENB, 165);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(460);
 if (hadap == utara){
    y_cor++;
  }
  else if(hadap == timur){
    x_cor++;
  }
  else if(hadap == selatan){
    y_cor--;
  }
  else if(hadap == barat){
    x_cor--;
  }
  }
  else if (RightSensor > 5) {
    analogWrite(ENA, 200 );
    analogWrite(ENB, 200);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(225);
     if(hadap == utara){
    hadap = timur;
  }
  else if (hadap == barat){
     hadap = utara;
  }
  else if (hadap == selatan){
    hadap = barat;
  }
  else if (hadap == timur){
    hadap = selatan;
  }
    analogWrite(ENA, 200);
    analogWrite(ENB, 165);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(460);
 if (hadap == utara){
    y_cor++;
  }
  else if(hadap == timur){
    x_cor++;
  }
  else if(hadap == selatan){
    y_cor--;
  }
  else if(hadap == barat){
    x_cor--;
  }

  }
  else{
     analogWrite(ENA, 200);
    analogWrite(ENB, 200);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(425); 
     if(hadap == utara){
    hadap = selatan;
  }
  else if (hadap == barat){
     hadap = timur;
  }
  else if (hadap == selatan){
    hadap = utara;
  }
  else if (hadap == timur){
    hadap = barat;
  }
  }
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  
}
}

void SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
}