int pinDataIn = 8;
int pinCS = 9;
int pinClock = 10;

// define max7219 registers
byte max7219_reg_noop        = 0x00;

// Columns of LEDs on the matrix
byte max7219_reg_digit0      = 0x01;
byte max7219_reg_digit1      = 0x02;
byte max7219_reg_digit2      = 0x03;
byte max7219_reg_digit3      = 0x04;
byte max7219_reg_digit4      = 0x05;
byte max7219_reg_digit5      = 0x06;
byte max7219_reg_digit6      = 0x07;
byte max7219_reg_digit7      = 0x08;
// End of columns of LEDs

// Other MAX7219 registers (commands)
byte max7219_reg_decodeMode  = 0x09;
byte max7219_reg_intensity   = 0x0a;
byte max7219_reg_scanLimit   = 0x0b;
byte max7219_reg_shutdown    = 0x0c;
byte max7219_reg_displayTest = 0x0f;

// Global vars
unsigned char sprite[] = {
  B00101000, 
  B00010000, 
  B00101000};
unsigned char msg[9] = {};

// ------------------------------------------------------------------
// SET UP     SET UP     SET UP     SET UP     SET UP     SET UP
// ------------------------------------------------------------------
void setup () {
  // Set GPIOs to correct mode for talking to MAX7214
  pinMode(pinDataIn, OUTPUT);
  pinMode(pinClock,  OUTPUT);
  pinMode(pinCS,   OUTPUT);
  digitalWrite(pinClock, HIGH);

  //initiation of all the max 7219s
  write2Display (max7219_reg_scanLimit, 0x07);   // use all 'digits'
  write2Display (max7219_reg_decodeMode, 0x00);  // using an led matrix (not 7-segment digits)
  write2Display (max7219_reg_shutdown, 0x01);    // not in shutdown mode
  write2Display (max7219_reg_displayTest, 0x00); // no display test (all LEDs on)
  write2Display (max7219_reg_intensity, 0x01);   // Set brightness 01 to 0F

  // Clear down any noise data lying around (else LEDs will turn on randomly)
  for (int digit = 1; digit <= 8; digit++) {
    write2Display(digit, 0);
  }

  // Small delay after clearing the display to show what's happening
  delay(1000);

  // Initialise buffer
  msg[8] = sprite[0];
  msg[7] = sprite[1];
  msg[6] = sprite[2];
}




// ------------------------------------------------------------------
// MAIN LOOP      MAIN LOOP      MAIN LOOP      MAIN LOOP      MAIN LOOP
// ------------------------------------------------------------------
void loop () {

  // 1  2   3  4  5  6  7  8
  //            <--- x  x  ?

  for (int buf = 1; buf <= 8; buf ++) {
    write2Display(buf, msg[buf]);
  }

  // Move the buffer to the left
  char keep = msg[1];
  for (int buf = 1; buf < 8 ; buf++) {
    msg[buf] = msg[buf + 1];
  }

  msg[8] = keep;

  delay(150);
}

// Send bytes (16 bits) to MAX7219
void write2Display ( byte maxRegister, byte maxData) {

  // Set Chip Select LOW so MAX7219 is ready for data
  digitalWrite(pinCS, LOW);

  // Send the 'command' byte first
  shiftOut(pinDataIn, pinClock, MSBFIRST, maxRegister);

  // Now send the 'data' byte
  shiftOut(pinDataIn, pinClock, MSBFIRST, maxData);

  // All done, set the CS HIGH again
  digitalWrite(pinCS, HIGH);
}
