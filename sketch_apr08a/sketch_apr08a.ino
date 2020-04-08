#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'0', '4', '8', 'C'}, {'1', '5', '9', 'D'},
  {'2', '6', 'A', 'E'}, {'3', '7', 'B', 'F'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {10, 9 , 8 , 7 };
Keypad keypad =
  Keypad( makeKeymap(keys), rowPins,
          colPins, ROWS, COLS );
void setup() {
  Serial.begin(9600);

}

void loop() {
  char key = keypad.getKey(); // 讀取
  if (key != NO_KEY) {
    Serial.println(key);
  }
}
