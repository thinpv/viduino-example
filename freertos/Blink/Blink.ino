
static void blinkThread(void *pvParameters)
{
  ( void ) pvParameters;
  for (;;)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  xTaskCreate(blinkThread, "blink", 1024, NULL, tskIDLE_PRIORITY + 2, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
