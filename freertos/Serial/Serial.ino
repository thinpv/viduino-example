static void s1Thread(void *pvParameters)
{
  ( void ) pvParameters;
  for (;;)
  {
    Serial.println("s1Thread");
    delay(200);
  }
}

static void s2Thread(void *pvParameters)
{
  ( void ) pvParameters;
  for (;;)
  {
    Serial.println("s2Thread");
    delay(500);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(s1Thread, "s1Thread", 1024, NULL, tskIDLE_PRIORITY + 2, NULL);
  xTaskCreate(s2Thread, "s2Thread", 1024, NULL, tskIDLE_PRIORITY + 2, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
