// Spencer Kulbacki
// Alphabet wall costume from Stranger things
// 10/27/16

#include "FastLED.h"
#define NUM_LEDS 29
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];  //needed for the FastLED function
//char letter[] = "rip barb.";  // space = pause in lights; .= long pause (end of message)
char message [30];
char watLetter;
int messageNum = 0; //the message number to be shown
int longPulse = 700;  // 700 is good
int shortPulse = 400; // 400 is good

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  //
  //    DONT FORGET TO CHANGE THE RANDOM # TO MATCH THE # OF CASES YOU HAVE FOR MESSAGES!!!
  //
  //            this one \/
  messageNum = random(1, 28);  //picks random case to get message from
//    messageNum = 22; //for debugging
  caseMessage();  //gets message from that case


  // does the actual blinking
  for (int i = 0; i < strlen(message); i++) {
    watLetter = message[i];
    Serial.println(messageNum); //debugging
    Serial.print(watLetter);    //debugging
    caseLetters();
  }

} //end loop


void caseMessage() {
  switch (messageNum) {
    case 1:
      {
        strncpy(message, "rip barb.", 25);   //copies the first 25 chars  of "rip barb," into the 'message'char
      }
      break;

    case 2:
      {
        strncpy(message, "run.", 25);
        //strncpy(message, "abcdefghijklmnopqrstuvwxyz.", 30);    //for debugging

      }
      break;

    case 3:
      {
        strncpy(message, "right here.", 25);
      }
      break;

    case 4:
      {
        strncpy(message, "will byers.", 25);
      }
      break;

    case 5:
      {
        strncpy(message, "upside down.", 25);
      }
      break;

    case 6:
      {
        strncpy(message, "demorgorgon.", 25);
      }
      break;

    case 7:
      {
        strncpy(message, "mike.", 25);
      }
      break;

    case 8:
      {
        strncpy(message, "eleven.", 25);
      }
      break;

    case 9:
      {
        strncpy(message, "will.", 25);
      }
      break;

    case 10:
      {
        strncpy(message, "lucas.", 25);
      }
      break;

    case 11:
      {
        strncpy(message, "dustin.", 25);
      }
      break;

    case 12:
      {
        strncpy(message, "joyce.", 25);
      }
      break;

    case 13:
      {
        strncpy(message, "jonathan.", 25);
      }
      break;

    case 14:
      {
        strncpy(message, "nancy.", 25);
      }
      break;

    case 15:
      {
        strncpy(message, "help.", 25);
      }
      break;

    case 16:
      {
        strncpy(message, "what did I do.", 25);
      }
      break;

    case 17:
      {
        strncpy(message, "hawkins.", 25);
      }
      break;

    case 18:
      {
        strncpy(message, "mom.", 25);
      }
      break;

    case 19:
      {
        strncpy(message, "friends dont lie.", 25);
      }
      break;

    case 20:
      {
        strncpy(message, "blood.", 25);
      }
      break;

    case 21:
      {
        strncpy(message, "stranger things.", 25);
      }
      break;

    case 22:
      {
        strncpy(message, "rip barb.", 25);   //copies the first 25 chars  of "rip barb," into the 'message'char
      }
      break;

    case 23:
      {
        strncpy(message, "spencer", 25);
      }
      break;

    case 24:
      {
        strncpy(message, "rit.", 26);
      }
      break;

    case 25:
      {
        strncpy(message, "get out.", 25);
      }
      break;

    case 26:
      {
        strncpy(message, "cold.", 25);
      }
      break;

    case 27:
      {
        strncpy(message, "csh.", 25);
      }
      break;

    case 28:
      {
        strncpy(message, "lost.", 25);
      }
      break;

    default:
      strncpy(message, "aaa", 25);
      //Serial.println("aa.");
      break;
  }
}

void caseLetters() {
  switch (watLetter) {
    case 'a':
      {
        leds[0] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[0] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'b':
      {
        leds[1] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[1] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'c':
      {
        leds[2] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[2] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'd':
      {
        leds[3] = CRGB::Blue;
        FastLED.show();
        delay(longPulse);
        leds[3] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'e':
      {
        leds[4] = CRGB::Yellow;
        FastLED.show();
        delay(longPulse);
        leds[4] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'f':
      {
        leds[5] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[5] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'g':
      {
        leds[6] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[6] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;
    //end of row 1
    case 'h':
      {
        leds[14] = CRGB::Blue;
        FastLED.show();
        delay(longPulse);
        leds[14] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'i':
      {
        leds[13] = CRGB::Yellow;
        FastLED.show();
        delay(longPulse);
        leds[13] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'j':
      {
        leds[12] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[12] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'k':
      {
        leds[11] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[11] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'l':
      {
        leds[10] = CRGB::Blue;
        FastLED.show();
        delay(longPulse);
        leds[10] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;
    case 'm':
      {
        leds[9] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[9] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'n':
      {
        leds[8] = CRGB::Yellow;
        FastLED.show();
        delay(longPulse);
        leds[8] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;
    // end of row 2
    case 'o':
      {
        leds[16] = CRGB::Blue;
        FastLED.show();
        delay(longPulse);
        leds[16] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'p':
      {
        leds[17] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[17] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'q':
      {
        leds[18] = CRGB::Yellow;
        FastLED.show();
        delay(longPulse);
        leds[18] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'r':
      {
        leds[19] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[19] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 's':
      {
        leds[20] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[20] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 't':
      {
        leds[21] = CRGB::Blue;
        FastLED.show();
        delay(longPulse);
        leds[21] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'u':
      {
        leds[22] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[22] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;
    // end or row 3
    case 'v':
      {
        leds[28] = CRGB::Green;
        FastLED.show();
        delay(longPulse);
        leds[28] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'w':
      {
        leds[27] = CRGB::Blue;
        FastLED.show();
        delay(longPulse);
        leds[27] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'x':
      {
        leds[26] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[26] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'y':
      {
        leds[25] = CRGB::Yellow;
        FastLED.show();
        delay(longPulse);
        leds[25] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case 'z':
      {
        leds[24] = CRGB::Red;
        FastLED.show();
        delay(longPulse);
        leds[24] = CRGB::Black;
        FastLED.show();
        delay(shortPulse);
      }
      break;

    case ' ':   // "Space"
      {
        delay(longPulse);
        delay(shortPulse);
      }
      break;

    case '.':   //long pause
      {
        delay(1200);
        delay(1200);
      }
      break;
    default:
      delay(shortPulse);
      break;
  }// end letter case statment
} //end case letter function

