#define BLYNK_TEMPLATE_ID "TMPL6JALvofta"
#define BLYNK_TEMPLATE_NAME "smart clothesline"
#define BLYNK_AUTH_TOKEN "f-j7khwIqCyeY29Wl4pF96CaWjnXBFIj"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <math.h>

// ===== WIFI =====
char ssid[] = "Le Minerale";
char pass[] = "gosong12";

// ===== PIN =====
const int rainPin  = 5;
const int tempPin  = 4;
const int servoPin = 18;
const int redPin   = 16;
const int greenPin = 17;

// ===== NTC CONFIG =====
const float R1   = 10000.0;
const float Beta = 3950.0;
const float To   = 298.15;
const float Ro   = 10000.0;

Servo jemuran;
BlynkTimer timer;

int manualMode = 0;
bool rainBefore = false;

// ===== MODE MANUAL (V3) =====
BLYNK_WRITE(V3) {
  manualMode = param.asInt();

  if (manualMode == 1) {
    jemuran.write(90); 
  } else {
    jemuran.write(0);
  }
}

void sendData() {

  // ==== BACA SUHU ====
  int adc = analogRead(tempPin);
  float voltage = adc * (3.3 / 4095.0);
  float Rt = R1 * (voltage / (3.3 - voltage));
  float tempK = 1.0 / ((1.0 / To) + (1.0 / Beta) * log(Rt / Ro));
  float tempC = (tempK - 273.15) - 3.0;

  // ==== BACA HUJAN ====
  bool isRaining = (digitalRead(rainPin) == LOW);

  // ==== NOTIFIKASI (ANTI SPAM) ====
  if (isRaining && !rainBefore) {
    Blynk.logEvent("hujan");
  }

  if (!isRaining && rainBefore) {
    Blynk.logEvent("cerah");
  }

  rainBefore = isRaining;

  // ==== MODE OTOMATIS ====
  if (manualMode == 0) {
    if (isRaining) {
      jemuran.write(90);
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
    } else {
      jemuran.write(0);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
  }

  // ==== KIRIM DATA KE BLYNK ====
  Blynk.virtualWrite(V0, tempC);
  Blynk.virtualWrite(V1, isRaining ? 1 : 0);

  // ==== DEBUG SERIAL ====
  Serial.print("Suhu: ");
  Serial.print(tempC);
  Serial.print(" | Hujan: ");
  Serial.println(isRaining ? "YA" : "TIDAK");
}

void setup() {

  Serial.begin(115200);
  delay(1000);

  pinMode(rainPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  jemuran.attach(servoPin);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}
