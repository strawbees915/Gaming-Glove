#include <Keyboard.h>

const int b1 = 2;  // index
const int b2 = 3;  // middle
const int b3 = 4;  // ring
const int b4 = 5;  // pinky

void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // read buttons
  bool p1 = digitalRead(b1) == LOW;
  bool p2 = digitalRead(b2) == LOW;
  bool p3 = digitalRead(b3) == LOW;
  bool p4 = digitalRead(b4) == LOW;

  // single presses
  if (p1 && !p2 && !p3 && !p4) Keyboard.write('a');
  if (p2 && !p1 && !p3 && !p4) Keyboard.write('d');
  if (p3 && !p1 && !p2 && !p4) Keyboard.write('w');
  if (p4 && !p1 && !p2 && !p3) Keyboard.write('s');

  // combinations
  if (p1 && p2 && p3 && p4) keyboard.write('f');
  delay(200); // debounce
}
