const int start = 7;
const int pirpin = 8;
const int alarmpin = 16;
const int ledON = 15;
const int ledOFF = 14;
bool ON;
bool ALM;
unsigned long alarmtime;

void setup() {
  // put your setup code here, to run once:
  // set the digital pin as output/input:
  pinMode(start, INPUT);
  pinMode(pirpin, INPUT);
  pinMode(alarmpin, OUTPUT);
  pinMode(ledON, OUTPUT);
  pinMode(ledOFF, OUTPUT);
  ON = false;
  ALM = false;
  alarmtime=0;
  digitalWrite(ledON, LOW);
  digitalWrite(ledOFF, HIGH);
  //to set alarm OFF alarm pin is HIGH
  digitalWrite(alarmpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  button();
  alarmcontrol(alarmtime);
  if (ON == true){
      digitalWrite(ledON, HIGH);
      digitalWrite(ledOFF, LOW);
      if(digitalRead(pirpin) == HIGH){
        //starts the alarm
        ALM=true;
        alarmtime = millis();
      }
    } else{
    digitalWrite(ledON, LOW);
    digitalWrite(ledOFF, HIGH);
    ALM=false;
  }

}

/*
 * toggles ON when start is pressed.
 */
void button(){
  if (digitalRead(start)==LOW){
    Serial.print("button pressed\n");
    if (ON == true){
      ON = false;
      delay(2000);
    } else{
      ON = true;
      delay(10000);
    }    
  }
}

/*
 * controls the alarm
 * the alarm sounds 10 sec
 */

void alarmcontrol(unsigned long almtime){
  if ((ALM == true)&& ((millis()-almtime)<10000)){
    //alarm on ==> pin high
    digitalWrite(alarmpin, HIGH);
  } else{
    //alarm off ==> pin low
    digitalWrite(alarmpin, LOW);    
  }
}
