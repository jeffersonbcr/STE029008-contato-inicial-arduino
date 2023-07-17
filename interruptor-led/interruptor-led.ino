volatile int botao = 0;
int led = 0;

enum State_t
{
  OFF = 0,
  E1 = 1,
  ON = 2,
  E2 = 3
};
State_t state = OFF;

void botao_isr()
{
  static unsigned long ultima_interrupcao = 0;
  static const unsigned long tempo_botao = 50;

  unsigned long agora = millis();
  if ((agora - ultima_interrupcao) >= tempo_botao)
  {
    Serial.println("Interrupção");
    botao = 1;
    ultima_interrupcao = agora;
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  state = OFF;
  pinMode(13, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), botao_isr, RISING);
}
void loop()
{
  noInterrupts();
  int b = botao;
  botao = 0;
  interrupts();
  switch (state)
  {
  case OFF:
    if (b == 1)
    {
      led = 1;
      Serial.println("In OFF and going to E1");
      state = E1;
      attachInterrupt(digitalPinToInterrupt(2), botao_isr, LOW);
    }
    break;
  case E1:

    if (b == 1)
    {
      led = 1;
      Serial.println("In E1 and going to ON");
      state = ON;
      attachInterrupt(digitalPinToInterrupt(2), botao_isr, RISING);
    }
    break;
  case ON:
    if (b == 1)
    {
      led = 0;
      Serial.println("In ON and going to E2");
      state = E2;
      attachInterrupt(digitalPinToInterrupt(2), botao_isr, LOW);
    }

    break;

  case E2:
    if (b == 1)
    {
      led = 0;
      Serial.println("In E2 and going to OFF");
      state = OFF;
      attachInterrupt(digitalPinToInterrupt(2), botao_isr, RISING);
    }
    break;

  default:
    break;
  }
  digitalWrite(13, led);
  delay(50);
}