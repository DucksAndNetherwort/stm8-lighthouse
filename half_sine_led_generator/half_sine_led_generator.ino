int led = PC3;
int inBright = PD1;
float brightnessMultiplier = 2;
int inSpeed = PD2;
int speedModifier = 10;

#define SIN_LEN 512
static const uint8_t sin_table[] =
{
    128, 129, 131, 132, 134, 135, 137, 138, 140, 142, 143, 145, 146, 148, 149, 151,
    152, 154, 155, 157, 158, 160, 162, 163, 165, 166, 167, 169, 170, 172, 173, 175,
    176, 178, 179, 181, 182, 183, 185, 186, 188, 189, 190, 192, 193, 194, 196, 197,
    198, 200, 201, 202, 203, 205, 206, 207, 208, 210, 211, 212, 213, 214, 215, 217,
    218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233,
    234, 234, 235, 236, 237, 238, 238, 239, 240, 241, 241, 242, 243, 243, 244, 245,
    245, 246, 246, 247, 248, 248, 249, 249, 250, 250, 250, 251, 251, 252, 252, 252,
    253, 253, 253, 253, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255,
};

inline static uint8_t sinSample(uint16_t i) {
    uint16_t newI = i % (SIN_LEN/2);
    newI = (newI >= (SIN_LEN/4)) ? (SIN_LEN/2 - newI -1) : newI;
    uint8_t sine = sin_table[newI];
    return (i >= (SIN_LEN/2)) ? (255 - sine) : sine;
}

void setup() {
    pinMode(led, OUTPUT);
    pinMode(inBright, INPUT_PULLUP);
    pinMode(inSpeed, INPUT_PULLUP);

}

void checkBright() {
  uint32_t i = 0;
  if (!digitalRead(inBright)) {
    updateBright:
    if (brightnessMultiplier == 2) {
      brightnessMultiplier = 0.5;
    }
    else if (brightnessMultiplier == 0.5) {
      brightnessMultiplier = 1;
    }
    else if (brightnessMultiplier == 1) {
      brightnessMultiplier = 1.5;
    }
    else if (brightnessMultiplier == 1.5) {
      brightnessMultiplier = 2;
    }

    while(!digitalRead(inBright)) {
      analogWrite(led, 128 * brightnessMultiplier);
      i++;
      if (i == 700) {
        i = 0;
        goto updateBright;
      }
      delay(1);
    }
    digitalWrite(led, LOW);
  }
}

void checkSpeed() {
  uint32_t i = 0;
   if(!digitalRead(inSpeed)) {
    updateSpeed:
    if (speedModifier == 5) {
      speedModifier = 10;
    }
    else if (speedModifier == 10) {
      speedModifier = 15;
    }
    else if (speedModifier == 15) {
      speedModifier = 20;
    }
    else if (speedModifier == 20) {
      speedModifier = 25;
    }
    else if (speedModifier == 25) {
      speedModifier = 30;
    }
    else if (speedModifier == 30) {
      speedModifier = 5;
    }
    while(!digitalRead(inSpeed)) {
      analogWrite(led, 260 - (speedModifier * 8.5));
      i++;
      if (i == 700) {
        i = 0;
        goto updateSpeed;
      }
      delay(1);
    }
  }
}

uint16_t i;
int16_t sineOutput;
void loop() {
  i++;
  delay(speedModifier);
  sineOutput = sinSample(i) * 2;
  sineOutput = sineOutput - 127.5;
  if (sineOutput < 0) {
    sineOutput = 0;
  }
  sineOutput = sineOutput * brightnessMultiplier;
  analogWrite(led, sineOutput);

  checkBright();
  checkSpeed();
}
