// Pin configuration
const int rows[] = {8, 7, 6, 5, 4, 3, 2};
const int cols[] = {9, 10, 11, 12, 13};
const int buttonPin1 = A1;
const int buttonPin2 = A2;
const int buttonPin3 = A3;
const int tilt2 = A4;
const int tilt1 = A5;
const int buttonPin4 = A4;
const int buttonPin5= A5;
const int buzzerPin = A0;
const int potPin = A7;



const int thermistorPin = A6;
const int pullUpResistor = 1000;  // Pull-up resistor value (1kΩ)
const int R0 = 1000;              // Resistance of thermistor at 25°C (1kΩ)
const double Beta = 3950;         // Beta value
const double T0 = 298.15;         // Reference temperature in Kelvin (25°C)

// Bitmap for digits 0-9, 'C', and '.'
const byte digits[12][5] = {
  {B0111110, B1000101, B1001001, B1010001, B0111110}, // 0
  {B0000000, B0100001, B1111111, B0000001, B0000000}, // 1
  {B0100001, B1000011, B1000101, B1001001, B0110001}, // 2
  {B0100010, B1000001, B1001001, B1001001, B0110110}, // 3
  {B0001100, B0010100, B0100100, B1111111, B0000100}, // 4
  {B1111001, B1001001, B1001001, B1001001, B1000110}, // 5
  {B0111110, B1001001, B1001001, B1001001, B0000110}, // 6
  {B1000011, B1000100, B1001000, B1010000, B1100000}, // 7
  {B0110110, B1001001, B1001001, B1001001, B0110110}, // 8
  {B0110000, B1001001, B1001001, B1001001, B0111110}, // 9
  {B0111110, B1000001, B1000001, B1000001, B0100010}, // C
  {B0000000, B0000000, B0000010, B0000000, B0000000}  // Decimal point (.)
};

// Homescreen bitmaps: Morse Code and Hourglass
const byte homeScreen[5][5] = {
  {B0110100, B0110010, B0000010, B0110010, B0110100}, // Home
  {B0001000, B0000000, B0001000, B0001000, B0001000},  // Morse Code
  {B1100011, B1110111, B1111111, B1110111, B1100011},// Hourglass (Sandclock)
  {B0011100, B0100010, B0101010, B0100010, B0011100},// Persistance of Vision
  {B0000000, B0100000, B0001100, B0010010, B0010010}// Temprature
  
};

// Characters for Morse Code (to be filled by you)
const byte characters[36][5] = {
  {B0111111, B1001000, B1001000, B1001000, B0111111}, // A
  {B1111111, B1001001, B1001001, B1001001, B0110110}, // B
  {B0111110, B1000001, B1000001, B1000001, B0100010}, // C
  {B1111111, B1000001, B1000001, B1000001, B0111110}, // D
  {B1111111, B1001001, B1001001, B1001001, B1000001}, // E
  {B1111111, B1001000, B1001000, B1001000, B1000000}, // F
  {B0111110, B1000001, B1001001, B1001001, B0100110}, // G
  {B1111111, B0001000, B0001000, B0001000, B1111111}, // H
  {B0000000, B1000001, B1111111, B1000001, B0000000}, // I
  {B0000010, B0000001, B1000001, B1111110, B1000000}, // J
  {B1111111, B0001000, B0010100, B0100010, B1000001}, // K
  {B1111111, B0000001, B0000001, B0000001, B0000001}, // L
  {B1111111, B0100000, B0010000, B0100000, B1111111}, // M
  {B1111111, B0100000, B0010000, B0001000, B1111111}, // N
  {B0111110, B1000001, B1000001, B1000001, B0111110}, // O
  {B1111111, B1001000, B1001000, B1001000, B0110000}, // P
  {B0111110, B1000001, B1000101, B1000010, B0111101}, // Q
  {B1111111, B1001000, B1001100, B1001010, B0110001}, // R
  {B0110010, B1001001, B1001001, B1001001, B0100110}, // S
  {B1000000, B1000000, B1111111, B1000000, B1000000}, // T
  {B1111110, B0000001, B0000001, B0000001, B1111110}, // U
  {B1111100, B0000010, B0000001, B0000010, B1111100}, // V
  {B1111111, B0000010, B0001100, B0000010, B1111111}, // W
  {B1000001, B0100010, B0011100, B0100010, B1000001}, // X
  {B1000000, B0100000, B0011111, B0100000, B1000000}, // Y
  {B1000011, B1000101, B1001001, B1010001, B1100001}, // Z
  {B0111110, B1000101, B1001001, B1010001, B0111110}, // 0
  {B0000000, B0100001, B1111111, B0000001, B0000000}, // 1
  {B0100001, B1000011, B1000101, B1001001, B0110001}, // 2
  {B0100010, B1000001, B1001001, B1001001, B0110110}, // 3
  {B0001100, B0010100, B0100100, B1111111, B0000100}, // 4
  {B1111001, B1001001, B1001001, B1001001, B1000110}, // 5
  {B0111110, B1001001, B1001001, B1001001, B0000110}, // 6
  {B1000011, B1000100, B1001000, B1010000, B1100000}, // 7
  {B0110110, B1001001, B1001001, B1001001, B0110110}, // 8
  {B0110000, B1001001, B1001001, B1001001, B0111110}  // 9
};

// Morse code array: 1 = dot, 2 = dash, 0 = end of character
const byte morseCode[36][6] = {
 {1, 2, 0, 0, 0, 0}, // A: .-
  {2, 1, 1, 1, 0, 0}, // B: -...
  {2, 1, 2, 1, 0, 0}, // C: -.-.
  {2, 1, 1, 0, 0, 0}, // D: -..
  {1, 0, 0, 0, 0, 0}, // E: .
  {1, 1, 2, 1, 0, 0}, // F: ..-.
  {2, 2, 1, 0, 0, 0}, // G: --.
  {1, 1, 1, 1, 0, 0}, // H: ....
  {1, 1, 0, 0, 0, 0}, // I: ..
  {1, 2, 2, 2, 0, 0}, // J: .---
  {2, 1, 2, 0, 0, 0}, // K: -.-
  {1, 2, 1, 1, 0, 0}, // L: .-..
  {2, 2, 0, 0, 0, 0}, // M: --
  {2, 1, 0, 0, 0, 0}, // N: -.
  {2, 2, 2, 0, 0, 0}, // O: ---
  {1, 2, 2, 1, 0, 0}, // P: .--.
  {2, 2, 1, 2, 0, 0}, // Q: --.-
  {1, 2, 1, 0, 0, 0}, // R: .-.
  {1, 1, 1, 0, 0, 0}, // S: ...
  {2, 0, 0, 0, 0, 0}, // T: -
  {1, 1, 2, 0, 0, 0}, // U: ..-
  {1, 1, 1, 2, 0, 0}, // V: ...-
  {1, 2, 2, 0, 0, 0}, // W: .--
  {2, 1, 1, 2, 0, 0}, // X: -..-
  {2, 1, 2, 2, 0, 0}, // Y: -.--
  {2, 2, 1, 1, 0, 0}, // Z: --..
  // 0-9
  {2, 2, 2, 2, 2, 0}, // 0: -----
  {1, 2, 2, 2, 2, 0}, // 1: .----
  {1, 1, 2, 2, 2, 0}, // 2: ..---
  {1, 1, 1, 2, 2, 0}, // 3: ...--
  {1, 1, 1, 1, 2, 0}, // 4: ....-
  {1, 1, 1, 1, 1, 0}, // 5: .....
  {2, 1, 1, 1, 1, 0}, // 6: -....
  {2, 2, 1, 1, 1, 0}, // 7: --...
  {2, 2, 2, 1, 1, 0}, // 8: ---..
  {2, 2, 2, 2, 1, 0}  // 9: ----.
};

const byte patterns[][5] = {
    {B1100000, B1110000, B1110000, B1110000, B1100000},
    {B1100000, B1110000, B0111000, B1110000, B1100000},
    {B1100000, B1110000, B0110100, B1110000, B1100000},
    {B1100000, B1110000, B0110010, B1110000, B1100000},
    {B1100000, B1110000, B0110001, B1110000, B1100000},
    {B1100000, B1110000, B0111001, B0110000, B1100000},
    {B1100000, B1110000, B0110101, B0110000, B1100000},
    {B1100000, B1110000, B0110011, B0110000, B1100000},
    {B1100000, B1110000, B0110001, B0110001, B1100000},
    {B1100000, B0110000, B0111001, B0110001, B1100000},
    {B1100000, B0110000, B0110101, B0110001, B1100000},
    {B1100000, B0110000, B0110011, B0110001, B1100000},
    {B1100000, B0110001, B0110001, B0110001, B1100000},
    {B1100000, B0110001, B0111001, B0110001, B0100000},
    {B1100000, B0110001, B0110101, B0110001, B0100000},
    {B1100000, B0110001, B0110011, B0110001, B0100000},
    {B0100000, B0110001, B0111011, B0110001, B0100000},
    {B0100000, B0110001, B0110111, B0110001, B0100000},
    {B0100000, B0110001, B0110011, B0110011, B0100000},
    {B0100000, B0110001, B0110011, B0110001, B0100001},
    {B0100000, B0110001, B0011011, B0110001, B0100001},
    {B0100000, B0110001, B0010111, B0110001, B0100001},
    {B0100000, B0110011, B0010011, B0110001, B0100001},
    {B0100001, B0110001, B0010011, B0110001, B0100001},
    {B0100001, B0110001, B0010011, B0110001, B0100001},
    {B0100001, B0110001, B0011011, B0010001, B0100001},
    {B0100001, B0110001, B0010111, B0010001, B0100001},
    {B0100001, B0110001, B0010011, B0010011, B0100001},
    {B0100001, B0010001, B0011011, B0010011, B0100001},
    {B0100001, B0010001, B0010111, B0010011, B0100001},
    {B0100001, B0010011, B0010011, B0010011, B0100001},
    {B0100001, B0010011, B0011011, B0010011, B0000001},
    {B0100001, B0010011, B0010111, B0010011, B0000001},
    {B0000001, B0010011, B0011111, B0010011, B0000001},
    {B0000001, B0010011, B0010111, B0010111, B0000001},
    {B0000001, B0010011, B0010111, B0010011, B0000011},
    {B0000001, B0010011, B0011111, B0000011, B0000011},
    {B0000001, B0010111, B0010111, B0000011, B0000011},
    {B0000011, B0010011, B0010111, B0000011, B0000011},
    {B0000011, B0000011, B0011111, B0000011, B0000011},
    {B0000011, B0000011, B0010111, B0000111, B0000011},
    {B0000011, B0000011, B0001111, B0000111, B0000011},
    {B0000011, B0000111, B0000111, B0000111, B0000011}
};


// Reverse sand animation patterns
const byte reversePatterns[][5] = {
    {B0000011, B0000111, B0000111, B0000111, B0000011},
    {B0000011, B0000111, B0001110, B0000111, B0000011},
    {B0000011, B0000111, B0010110, B0000111, B0000011},
    {B0000011, B0000111, B0100110, B0000111, B0000011},
    {B0000011, B0000111, B1000110, B0000111, B0000011},
    {B0000011, B0000111, B1001110, B0000110, B0000011},
    {B0000011, B0000111, B1010110, B0000110, B0000011},
    {B0000011, B0000111, B1100110, B0000110, B0000011},
    {B0000011, B0000111, B1000110, B1000110, B0000011},
    {B0000011, B0000110, B1001110, B1000110, B0000011},
    {B0000011, B0000110, B1010110, B1000110, B0000011},
    {B0000011, B0000110, B1100110, B1000110, B0000011},
    {B0000011, B1000110, B1000110, B1000110, B0000011},
    {B0000011, B1000110, B1001110, B1000110, B0000010},
    {B0000011, B1000110, B1010110, B1000110, B0000010},
    {B0000011, B1000110, B1100110, B1000110, B0000010},
    {B0000010, B1000110, B1101110, B1000110, B0000010},
    {B0000010, B1000110, B1110110, B1000110, B0000010},
    {B0000010, B1000110, B1100110, B1100110, B0000010},
    {B0000010, B1000110, B1100110, B1000110, B1000010},
    {B0000010, B1000110, B1101100, B1000110, B1000010},
    {B0000010, B1000110, B1110100, B1000110, B1000010},
    {B0000010, B1100110, B1100100, B1000110, B1000010},
    {B1000010, B1000110, B1100100, B1000110, B1000010},
    {B1000010, B1000110, B1101100, B1000100, B1000010},
    {B1000010, B1000110, B1110100, B1000100, B1000010},
    {B1000010, B1000110, B1100100, B1100100, B1000010},
    {B1000010, B1000100, B1101100, B1100100, B1000010},
    {B1000010, B1000100, B1110100, B1100100, B1000010},
    {B1000010, B1100100, B1100100, B1100100, B1000010},
    {B1000010, B1100100, B1101100, B1100100, B1000000},
    {B1000010, B1100100, B1110100, B1100100, B1000000},
    {B1000000, B1100100, B1111100, B1100100, B1000000},
    {B1000000, B1100100, B1110100, B1110100, B1000000},
    {B1000000, B1100100, B1110100, B1100100, B1100000},
    {B1000000, B1100100, B1111000, B1100100, B1100000},
    {B1000000, B1110100, B1110000, B1100100, B1100000},
    {B1100000, B1100100, B1110000, B1100100, B1100000},
    {B1100000, B1100100, B1111000, B1100000, B1100000},
    {B1100000, B1100100, B1110000, B1110000, B1100000},
    {B1100000, B1100000, B1111000, B1110000, B1100000},
    {B1100000, B1110000, B1110000, B1110000, B1100000}

};

const byte A[5] = {
    B0111111,  // Col 1
    B1001000,  // Col 2
    B1001000,  // Col 3
    B1001000,  // Col 4
    B0111111,  // Col 5
};
// Bitmap for digits 0-9, 'C', and '.'
const byte Temp[12][5] = {
  {B0111110, B1000101, B1001001, B1010001, B0111110}, // 0
  {B0000000, B0100001, B1111111, B0000001, B0000000}, // 1
  {B0100001, B1000011, B1000101, B1001001, B0110001}, // 2
  {B0100010, B1000001, B1001001, B1001001, B0110110}, // 3
  {B0001100, B0010100, B0100100, B1111111, B0000100}, // 4
  {B1111001, B1001001, B1001001, B1001001, B1000110}, // 5
  {B0111110, B1001001, B1001001, B1001001, B0000110}, // 6
  {B1000011, B1000100, B1001000, B1010000, B1100000}, // 7
  {B0110110, B1001001, B1001001, B1001001, B0110110}, // 8
  {B0110000, B1001001, B1001001, B1001001, B0111110}, // 9
  {B0111110, B1000001, B1000001, B1000001, B0100010}, // C
  {B0000000, B0000000, B0000010, B0000000, B0000000}  // Decimal point (.)
};

// Global variables
volatile int currentProgramIndex = 0;
volatile int currentCharacterIndex = 0;
volatile int currentColumn = 0;
volatile int potValue = 0;       // Potentiometer value
static bool wasPOVmode = false;
bool morseMode = false;
bool hourglassMode = false;
bool POVmode = false;
bool tempMode = false;



bool buttonState1 = false;
bool lastButtonState1 = false;
bool buttonState2 = false;
bool lastButtonState2 = false;
bool buttonState3 = false;
bool lastButtonState3 = false;
bool buttonState4 = false;
bool lastButtonState4 = false;
bool buttonState5 = false;
bool lastButtonState5 = false;

const int numFrames1 = sizeof(patterns) / sizeof(patterns[0]);
const int numFrames2 = sizeof(reversePatterns) / sizeof(reversePatterns[0]);

int currentFrame = 0;
volatile bool updateFrame = false;
const long transitionTime = 5000;
long frameDelay1;
long frameDelay2;
bool animationComplete = false;
bool reverseMode = false;

volatile unsigned long lastBuzzerToggle = 0;
bool buzzerState = false;
bool buzzerOn = false;
unsigned long button1PressStart = 0; // Tracks when the button was pressed
bool button1LongPressDetected = false; // Flag to avoid multiple triggers

volatile byte buffer[50] = {0};  // Scrolling buffer for display
volatile int offset = 0;         // Offset for scrolling
volatile bool updateScroll = false;
const int scrollInterval = 150;  // Scrolling speed in ms
unsigned long lastScrollTime = 0;

void setup() {
  Serial.begin(9600);

  // Pin setup
  for (int i = 0; i < 7; i++) pinMode(rows[i], OUTPUT);
  for (int i = 0; i < 5; i++) pinMode(cols[i], OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tilt2, INPUT);
  pinMode(tilt1, INPUT);

  frameDelay1 = transitionTime / numFrames1;
  frameDelay2 = transitionTime / numFrames2;

  // Timer1 setup for LED refresh
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 249;  // Compare match value for 10ms (16MHz clock, prescaler 64)
  TCCR1B |= (1 << WGM12); // CTC mode
  TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 64
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void loop() {
    // Read buttons
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    buttonState4 = digitalRead(buttonPin4);
    buttonState5 = digitalRead(buttonPin5);

    bool tiltDown = !digitalRead(tilt2);
    bool tiltUp = !digitalRead(tilt1);
    static float lastTemperature = 0.0;  
    // Handle Button 1 Long Press for Home Screen
    if (buttonState1 == LOW && lastButtonState1 == HIGH) {
        button1PressStart = millis(); // Start the timer
        button1LongPressDetected = false; // Reset the flag
    }

    if (buttonState1 == LOW && millis() - button1PressStart >= 5000 && !button1LongPressDetected) {
        button1LongPressDetected = true;
        morseMode = hourglassMode = POVmode = tempMode = false;
        currentProgramIndex = 0; // Reset to home screen
        resetAnimation();
        clearAllLeds();
        Serial.println("Returned to Home Screen");
    }

    if (buttonState1 == HIGH && lastButtonState1 == LOW) {
        button1PressStart = 0; // Reset the timer
    }

    // Home Screen Navigation
    if (!morseMode && !hourglassMode && !POVmode && !tempMode) {
        if (lastButtonState1 == HIGH && buttonState1 == LOW) {
            currentProgramIndex = (currentProgramIndex + 1) % 5; // Move forward
            delay(100);
        }
        if (lastButtonState2 == HIGH && buttonState2 == LOW) {
            currentProgramIndex = (currentProgramIndex - 1 + 5) % 5; // Move backward
            delay(100);
        }
        if (lastButtonState3 == HIGH && buttonState3 == LOW) {
            // Select program
            if (currentProgramIndex == 1) morseMode = true;
            else if (currentProgramIndex == 2) hourglassMode = true;
            else if (currentProgramIndex == 3) POVmode = true;
            else if (currentProgramIndex == 4) {
                tempMode = true;
                offset = 0; // Reset scrolling offset
                lastScrollTime = millis(); // Reset scroll timing
            }
            delay(200);
        }
    }

    // Morse Mode Tutor Logic
    else if (morseMode) {
        if (lastButtonState1 == HIGH && buttonState1 == LOW) {
            currentCharacterIndex = (currentCharacterIndex + 1) % 36;
            delay(100);
        }
        if (lastButtonState2 == HIGH && buttonState2 == LOW) {
            currentCharacterIndex = (currentCharacterIndex - 1 + 36) % 36;
            delay(100);
        }
        if (lastButtonState3 == HIGH && buttonState3 == LOW) {
            playMorse(currentCharacterIndex);
            delay(100);
        }
    }

    // Hourglass Mode Logic
    else if (hourglassMode) {
        if (updateFrame) {
            if (tiltDown && !animationComplete && !reverseMode) smoothSandDown();
            if (tiltUp && !animationComplete && reverseMode) smoothSandUp();
            if (animationComplete) {
                buzzerOn = true;
                ringBuzzer();
            }
            if (tiltUp && !reverseMode) {
                reverseMode = true;
                resetAnimation();
            }
            if (tiltDown && reverseMode) {
                reverseMode = false;
                resetAnimation();
            }
        }
    }

    // Temperature Display Logic
    else if (tempMode) {
        if (millis() - lastScrollTime >= scrollInterval) {
            lastScrollTime = millis(); // Update scroll timer
            offset++; // Move scroll offset
            if (offset >= sizeof(buffer)) {
                offset = 0; // Reset scrolling
            }
            lastTemperature = calculateTemperature(); // Update temperature
            prepareBuffer(lastTemperature); // Prepare buffer
            Serial.print("Temperature: ");
            Serial.println(lastTemperature);
        }
    }
if (!POVmode && wasPOVmode) {
    OCR1A = 249;  // Reset Timer1 compare value to default (~10ms)
}

wasPOVmode = POVmode;
    // Update last button states
    lastButtonState1 = buttonState1;
    lastButtonState2 = buttonState2;
    lastButtonState3 = buttonState3;
    lastButtonState4 = buttonState4;
    lastButtonState5 = buttonState5;
}



// Optimized Timer1 ISR for smooth multiplexing
ISR(TIMER1_COMPA_vect) {
    static int colIndex = 0;
    static int potValue = 0;
    static int counter = 0;
    updateFrame = true;

    // Clear previous column
    digitalWrite(cols[colIndex], HIGH);
    for (int row = 0; row < 7; row++) {
        digitalWrite(rows[row], LOW);
    }

    // Move to the next column
    colIndex = (colIndex + 1) % 5;

    // Display content based on active mode
    if (POVmode) {
        // Read potentiometer every 50ms
        if (counter++ >= 10) {
            potValue = analogRead(potPin);
            OCR1A = map(potValue, 0, 1023, 499, 24999); // Adjusts interval dynamically
            counter = 0;
        }

        // Activate the rows for the new column based on the dynamic pattern
        for (int row = 0; row < 7; row++) {
            if (A[colIndex] & (1 << (6 - row))) { // Check if the bit is set in the pattern
                digitalWrite(rows[row], HIGH);   // Turn on the corresponding row
            }
        }
  
    } else if (hourglassMode) {
        // Hourglass animation logic
        byte pattern = reverseMode ? reversePatterns[currentFrame][colIndex] : patterns[currentFrame][colIndex];
        for (int row = 0; row < 7; row++) {
            digitalWrite(rows[row], (pattern & (1 << (6 - row))) ? HIGH : LOW);
        }
    } else if (morseMode) {
        // Morse code display logic
        byte pattern = characters[currentCharacterIndex][colIndex];
        for (int row = 0; row < 7; row++) {
            digitalWrite(rows[row], (pattern & (1 << (6 - row))) ? HIGH : LOW);
        }
    } else if (tempMode) {
        // Temperature scrolling logic
        byte pattern = buffer[(colIndex + offset) % sizeof(buffer)];
        for (int row = 0; row < 7; row++) {
            digitalWrite(rows[row], (pattern & (1 << (6 - row))) ? HIGH : LOW);
        }
    } else {
        // Home screen logic
        byte pattern = homeScreen[currentProgramIndex][colIndex];
        for (int row = 0; row < 7; row++) {
            digitalWrite(rows[row], (pattern & (1 << (6 - row))) ? HIGH : LOW);
        }
    }

    // Activate the new column
    digitalWrite(cols[colIndex], LOW);
}


void playMorse(int index) {
  for (int i = 0; morseCode[index][i] != 0; i++) {
    noTone(buzzerPin);
    if (morseCode[index][i] == 1) {
      tone(buzzerPin, 2000, 200);
      delay(700);
    } else if (morseCode[index][i] == 2) {
      tone(buzzerPin, 2000, 600);
      delay(1100);
    }
  }
  noTone(buzzerPin);
}
void smoothSandDown() {
    static unsigned long lastFrameTime = 0;
    if (millis() - lastFrameTime >= frameDelay1) {
        lastFrameTime = millis();
        if (currentFrame < numFrames1 - 1) {
            currentFrame++;
        } else {
            animationComplete = true;
        }
    }
}

void smoothSandUp() {
    static unsigned long lastFrameTime = 0;
    if (millis() - lastFrameTime >= frameDelay2) {
        lastFrameTime = millis();
        if (currentFrame < numFrames2 - 1) {
            currentFrame++;
        } else {
            animationComplete = true;
        }
    }
}

void resetAnimation() {
    animationComplete = false;
    buzzerOn = false;
    currentFrame = 0;
    clearAllLeds();
    noTone(buzzerPin);  // Explicitly stop the buzzer
}

void ringBuzzer(){
    if (buzzerOn) {
        tone(buzzerPin, 4000); // Generate a 1kHz tone
    } 
    else{
        noTone(buzzerPin);}  // Ensure the tone is stopped
}
void clearAllLeds() {
    for (int col = 0; col < 5; col++) {
        digitalWrite(cols[col], HIGH);
        for (int row = 0; row < 7; row++) {
            digitalWrite(rows[row], LOW);
        }
    }
}
// Calculate temperature
double calculateTemperature() {
  long sensorValue = analogRead(thermistorPin);
  double voltage = sensorValue * (5.0 / 1023.0);
  double thermistorResistance = pullUpResistor * ((5.0 - voltage) / voltage);
  double temperatureKelvin = 1.0 / ((1.0 / T0) + (1.0 / Beta) * log(thermistorResistance / R0));
  return temperatureKelvin - 273.15;
}

// Scroll temperature data into buffer
void prepareBuffer(float temperature) {
  char tempString[7];
  dtostrf(temperature, 4, 1, tempString);
  strcat(tempString, " C");

  int bufferIndex = 0;
  memset(buffer, 0, sizeof(buffer));

  for (int i = 0; tempString[i] != '\0'; i++) {
    int digit = (tempString[i] >= '0' && tempString[i] <= '9') ? tempString[i] - '0' :
                (tempString[i] == 'C') ? 10 :
                (tempString[i] == '.') ? 11 : -1;

    if (digit >= 0) {
      for (int col = 0; col < 5; col++) {
        buffer[bufferIndex++] = digits[digit][col];
      }
      buffer[bufferIndex++] = 0;  // Spacing
    }
  }
}
