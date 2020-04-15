#include<Keypad.h>
#include<SevSeg.h>
SevSeg sevseg;

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={{'F','B','7','3'},{'E','A','6','2'},{'D','9','5','1'},{'C','8','4','0'}};
byte rowPins[ROWS]={7,8,9,10};
byte colPins[COLS]={11,12,13,14};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup() {
  byte numDigits =1;
  byte digitPins[]={17};
  byte segmentPins[]={2,3,4,5,6,15,16};
  sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
  sevseg.setBrightness(70);
  Serial.begin(9600);

}

void loop() {
  char key =keypad.getKey();
  if(key!=NO_KEY){
      sevseg.setNumber(key-'0',0);
  }
  sevseg.refreshDisplay();
}
