
//#define DEBUG

// Required libraries
#include <MaxMatrix.h>
#include <avr/pgmspace.h>

// This will be saveded into FLASH - saves valuable program memory
PROGMEM const unsigned char CH[] = {
  3, 8, B0000000, B0000000, B0000000, B0000000, B0000000, // space
  1, 8, B1011111, B0000000, B0000000, B0000000, B0000000, // !
  3, 8, B0000011, B0000000, B0000011, B0000000, B0000000, // "
  5, 8, B0010100, B0111110, B0010100, B0111110, B0010100, // #
  4, 8, B0100100, B1101010, B0101011, B0010010, B0000000, // $
  5, 8, B1100011, B0010011, B0001000, B1100100, B1100011, // %
  5, 8, B0110110, B1001001, B1010110, B0100000, B1010000, // &
  1, 8, B0000011, B0000000, B0000000, B0000000, B0000000, // '
  3, 8, B0011100, B0100010, B1000001, B0000000, B0000000, // (
  3, 8, B1000001, B0100010, B0011100, B0000000, B0000000, // )
  5, 8, B0101000, B0011000, B0001110, B0011000, B0101000, // *
  5, 8, B0001000, B0001000, B0111110, B0001000, B0001000, // +
  2, 8, B10110000, B1110000, B0000000, B0000000, B0000000, // ,
  4, 8, B0001000, B0001000, B0001000, B0001000, B0000000, // -
  2, 8, B1100000, B1100000, B0000000, B0000000, B0000000, // .
  4, 8, B1100000, B0011000, B0000110, B0000001, B0000000, // /
  4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // 0
  3, 8, B1000010, B1111111, B1000000, B0000000, B0000000, // 1
  4, 8, B1100010, B1010001, B1001001, B1000110, B0000000, // 2
  4, 8, B0100010, B1000001, B1001001, B0110110, B0000000, // 3
  4, 8, B0011000, B0010100, B0010010, B1111111, B0000000, // 4
  4, 8, B0100111, B1000101, B1000101, B0111001, B0000000, // 5
  4, 8, B0111110, B1001001, B1001001, B0110000, B0000000, // 6
  4, 8, B1100001, B0010001, B0001001, B0000111, B0000000, // 7
  4, 8, B0110110, B1001001, B1001001, B0110110, B0000000, // 8
  4, 8, B0000110, B1001001, B1001001, B0111110, B0000000, // 9
  2, 8, B01010000, B0000000, B0000000, B0000000, B0000000, // :
  2, 8, B10000000, B01010000, B0000000, B0000000, B0000000, // ;
  3, 8, B0010000, B0101000, B1000100, B0000000, B0000000, // <
  3, 8, B0010100, B0010100, B0010100, B0000000, B0000000, // =
  3, 8, B1000100, B0101000, B0010000, B0000000, B0000000, // >
  4, 8, B0000010, B1011001, B0001001, B0000110, B0000000, // ?
  5, 8, B0111110, B1001001, B1010101, B1011101, B0001110, // @
  4, 8, B1111110, B0010001, B0010001, B1111110, B0000000, // A
  4, 8, B1111111, B1001001, B1001001, B0110110, B0000000, // B
  4, 8, B0111110, B1000001, B1000001, B0100010, B0000000, // C
  4, 8, B1111111, B1000001, B1000001, B0111110, B0000000, // D
  4, 8, B1111111, B1001001, B1001001, B1000001, B0000000, // E
  4, 8, B1111111, B0001001, B0001001, B0000001, B0000000, // F
  4, 8, B0111110, B1000001, B1001001, B1111010, B0000000, // G
  4, 8, B1111111, B0001000, B0001000, B1111111, B0000000, // H
  3, 8, B1000001, B1111111, B1000001, B0000000, B0000000, // I
  4, 8, B0110000, B1000000, B1000001, B0111111, B0000000, // J
  4, 8, B1111111, B0001000, B0010100, B1100011, B0000000, // K
  4, 8, B1111111, B1000000, B1000000, B1000000, B0000000, // L
  5, 8, B1111111, B0000010, B0001100, B0000010, B1111111, // M
  5, 8, B1111111, B0000100, B0001000, B0010000, B1111111, // N
  4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // O
  4, 8, B1111111, B0001001, B0001001, B0000110, B0000000, // P
  4, 8, B0111110, B1000001, B1000001, B10111110, B0000000, // Q
  4, 8, B1111111, B0001001, B0001001, B1110110, B0000000, // R
  4, 8, B1000110, B1001001, B1001001, B0110010, B0000000, // S
  5, 8, B0000001, B0000001, B1111111, B0000001, B0000001, // T
  4, 8, B0111111, B1000000, B1000000, B0111111, B0000000, // U
  5, 8, B0001111, B0110000, B1000000, B0110000, B0001111, // V
  5, 8, B0111111, B1000000, B0111000, B1000000, B0111111, // W
  5, 8, B1100011, B0010100, B0001000, B0010100, B1100011, // X
  5, 8, B0000111, B0001000, B1110000, B0001000, B0000111, // Y
  4, 8, B1100001, B1010001, B1001001, B1000111, B0000000, // Z
  2, 8, B1111111, B1000001, B0000000, B0000000, B0000000, // [
  4, 8, B0000001, B0000110, B0011000, B1100000, B0000000, // backslash
  2, 8, B1000001, B1111111, B0000000, B0000000, B0000000, // ]
  3, 8, B0000010, B0000001, B0000010, B0000000, B0000000, // hat
  4, 8, B1000000, B1000000, B1000000, B1000000, B0000000, // _
  2, 8, B0000001, B0000010, B0000000, B0000000, B0000000, // `
  4, 8, B0100000, B1010100, B1010100, B1111000, B0000000, // a
  4, 8, B1111111, B1000100, B1000100, B0111000, B0000000, // b
  4, 8, B0111000, B1000100, B1000100, B0101000, B0000000, // c
  4, 8, B0111000, B1000100, B1000100, B1111111, B0000000, // d
  4, 8, B0111000, B1010100, B1010100, B0011000, B0000000, // e
  3, 8, B0000100, B1111110, B0000101, B0000000, B0000000, // f
  4, 8, B10011000, B10100100, B10100100, B01111000, B0000000, // g
  4, 8, B1111111, B0000100, B0000100, B1111000, B0000000, // h
  3, 8, B1000100, B1111101, B1000000, B0000000, B0000000, // i
  4, 8, B1000000, B10000000, B10000100, B1111101, B0000000, // j
  4, 8, B1111111, B0010000, B0101000, B1000100, B0000000, // k
  3, 8, B1000001, B1111111, B1000000, B0000000, B0000000, // l
  5, 8, B1111100, B0000100, B1111100, B0000100, B1111000, // m
  4, 8, B1111100, B0000100, B0000100, B1111000, B0000000, // n
  4, 8, B0111000, B1000100, B1000100, B0111000, B0000000, // o
  4, 8, B11111100, B0100100, B0100100, B0011000, B0000000, // p
  4, 8, B0011000, B0100100, B0100100, B11111100, B0000000, // q
  4, 8, B1111100, B0001000, B0000100, B0000100, B0000000, // r
  4, 8, B1001000, B1010100, B1010100, B0100100, B0000000, // s
  3, 8, B0000100, B0111111, B1000100, B0000000, B0000000, // t
  4, 8, B0111100, B1000000, B1000000, B1111100, B0000000, // u
  5, 8, B0011100, B0100000, B1000000, B0100000, B0011100, // v
  5, 8, B0111100, B1000000, B0111100, B1000000, B0111100, // w
  5, 8, B1000100, B0101000, B0010000, B0101000, B1000100, // x
  4, 8, B10011100, B10100000, B10100000, B1111100, B0000000, // y
  3, 8, B1100100, B1010100, B1001100, B0000000, B0000000, // z
  3, 8, B0001000, B0110110, B1000001, B0000000, B0000000, // {
  1, 8, B1111111, B0000000, B0000000, B0000000, B0000000, // |
  3, 8, B1000001, B0110110, B0001000, B0000000, B0000000, // }
  4, 8, B0001000, B0000100, B0001000, B0000100, B0000000, // ~
};

// Define our GPIO pins to talk to the MAX7219
#define maxData 8
#define maxCS 9
#define maxCLK 10

// Delay between character printing
#define delayMs 15

// How many physical display units?
int maxInUse = 12;

// Instantiate the matrix object
MaxMatrix m(maxData, maxCS, maxCLK, maxInUse);

// Holding area for our character
byte buffer[20];

// What do we want to print? See alternative method of entering data via serial window
char msg[] = "Character scrolling with the MAX7219 LED Matrix!        ";

// ---------------------------------------------------
// SETUP      SETUP      SETUP      SETUP      SETUP
// ---------------------------------------------------
void setup()
{
  Serial.begin(9600);
  delay(500);

#ifdef DEBUG
  Serial.println("Setup started");
#endif

  // Set our GPIO pins as OUTPUT
  pinMode (maxData, OUTPUT);
  pinMode (maxCS, OUTPUT);
  pinMode (maxCLK, OUTPUT);

  // Initialise the displays
  m.init();
  m.clear();
  m.setIntensity(0x05);

#ifdef DEBUG
  Serial.println("Setup finished");
#endif
}

// ---------------------------------------------------
// LOOP    LOOP    LOOP    LOOP    LOOP    LOOP   LOOP
// ---------------------------------------------------
void loop()
{
  // If nothing has been 'sent' via the serial window then
  // display the default message
  char newMsg[] = {};
  int nmCnt = 0;
  while (Serial.available()) {
    newMsg[nmCnt] = Serial.read();
    nmCnt++;
  }

  // Output the message, one char at a time
  if (nmCnt > 0) {
    for (int cnt=nmCnt;cnt < nmCnt + 10; cnt++){
      newMsg[cnt]= ' ';
    }
    printStringWithShift(newMsg, delayMs);
  } else {
    printStringWithShift(msg, delayMs);
  }

  // Clear the display
  delay(1000);
}

// ---------------------------------------------------
// PRINT MESSAGE AND SHIFT TO LEFT
// ---------------------------------------------------
void printStringWithShift(char* s, int shift_speed)
{
  // For each character in the supplied string, print it
  while (*s != 0)
  {
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

// ---------------------------------------------------
// PRINT CHARACTER AND SHIFT TO LEFT
// ---------------------------------------------------
void printCharWithShift(char c, int shift_speed)
{
#ifdef DEBUG
  Serial.println("Printing character: " + c);
#endif

  // If the value of the char is outside our ASCII range, ignore it
  // such as backspace, tab or newline
  if (c < 32) return;

  // Map the ascii value to our character array in EEPROM, that is
  // the nth character (so our first possible character [a space, hex 20, dec 32]
  // is mapped to the zero-th element in our array, for example
  c -= 32;

  // Now get that element from FLASh
  memcpy_P(buffer, CH + 7 * c, 7);

  // Writes to co-ords x,y with value buffer
  m.writeSprite(32, 0, buffer);

  // Clear the column immediately after the character (space col)
  m.setColumn(32 + buffer[0], 0);

  // Shift everything in the display left by width of next character
  // This is held in our array as second byte
  for (int i = 0; i < buffer[0] + 1; i++)
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}
