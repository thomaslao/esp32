
#define LEDC_CHANNEL_0     0

#define LEDC_TIMER_13_BIT  13

#define LEDC_BASE_FREQ     5000

#define LED_PIN            5

void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
  uint32_t duty = (8191 / valueMax) * min(value, valueMax);

  ledcWrite(channel, duty);
}

void setup() {
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(LED_PIN, LEDC_CHANNEL_0);
}

void loop() {
  ledcAnalogWrite(LEDC_CHANNEL_0, 1024);
  delay(3000);
  ledcAnalogWrite(LEDC_CHANNEL_0, 0);
  delay(3000);
}
