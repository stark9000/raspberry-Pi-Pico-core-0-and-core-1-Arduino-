int LED_1 = 2;
int BUZZ = 3;

int D = 0;

bool lock = false;


// The normal, core0 setup
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(LED_1, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (lock == false) {
    D++;
    if (D == 1) {
      Serial.println("starting core zero op");
    }
    delay(500);
    Serial.println(D);
    if (D == 20) {
      digitalWrite(LED_1, HIGH);
      digitalWrite(BUZZ, HIGH);
      delay(1000);
      digitalWrite(LED_1, LOW);
      digitalWrite(BUZZ, LOW);
      Serial.println("core zero done");
      Serial.println("switching to core 1");
      lock = true;
    }
  }
}

// Running on core1
void setup1() {
  pinMode(LED_1, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop1() {
  if (lock == true) {
    D++;
    if (D == 21) {
      Serial.println("starting core one op");
    }
    delay(500);
    Serial.println(D);
    if (D == 40) {
      lock = true;
      digitalWrite(LED_1, HIGH);
      digitalWrite(BUZZ, HIGH);
      delay(1000);
      digitalWrite(LED_1, LOW);
      digitalWrite(BUZZ, LOW);
      D = 0;
      Serial.println("core one done");
      Serial.println("switching to core 0");
      lock = false;
    }
  }
}
