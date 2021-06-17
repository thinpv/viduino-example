
void printTask(void *parameter);
void blinkTask(void *parameter);
// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreate(
      printTask,    /* Task function. */
      "print Task", /* name of task. */
      1000,        /* Stack size of task */
      NULL,         /* parameter of the task */
      1,            /* priority of the task */
      NULL);        /* Task handle to keep track of created task */

  xTaskCreate(
      blinkTask,    /* Task function. */
      "blink Task", /* name of task. */
      1000,        /* Stack size of task */
      NULL,         /* parameter of the task */
      1,            /* priority of the task */
      NULL);        /* Task handle to keep track of created task */
  vTaskDelete(NULL);
}

void printTask(void *parameter)
{
  for (;;)
  {
    Serial.println("this is print Task");
    delay(1000);
  }
  vTaskDelete(NULL);
}

void blinkTask(void *parameter)
{
  for (;;)
  {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(100);
  }
  vTaskDelete(NULL);
}

// the loop function runs over and over again forever
void loop()
{
  delay(100); // wait for a second
}
