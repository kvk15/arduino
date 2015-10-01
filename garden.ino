// IO pin
int ds0 = A0;  //soil sensor
int ds1 = A1;
int dw0 = A3;  // water sensor
int vcc = 1;   // +5V for muserment
int wled = 2;  // Red LED for water level
int pump0 = 3; // pump
int pump1 = 4;


void setup() {
  pinMode(vcc, OUTPUT);
  pinMode(wled, OUTPUT);
  //Serial.begin(9600); //for debug and calibrate moisture sensor
}

// check water level(min 0.5L)
void water(){
  int dw0val = analogRead(dw0);
  if (dw0val == 0){
    digitalWrite(wled, HIGH);
  }
  else{
    digitalWrite(wled, LOW);
  }
  //Serial.print("Water level: "); Serial.println(dw0val);
}

void loop(){
  digitalWrite(vcc, HIGH); // +5V ON for muserment
  delay(300); //wait power on the sensor
  int ds0val = analogRead(ds0); // read from analog sensor
  int ds1val = analogRead(ds1);
  water(); // check water level
  digitalWrite(vcc, LOW); // +5V OFF

  //Serial.print("Flower 1:\t"); Serial.println(ds0val); // print moisture soil to 
  //Serial.print("Flower 2:\t"); Serial.println(ds1val); // serial port(Ctrl+Shift+M in Arduino IDE)

  if (ds0val <= 500){
    digitalWrite(pump0, HIGH);
    delay(3000); // 3sec (about 125g of water)
    digitalWrite(pump0, LOW);
  }
  if (ds1val <= 400){
    digitalWrite(pump1, HIGH);
    delay(3000);
    digitalWrite(pump1, LOW)
  }

  delay(60*1000) // 1minute
}

