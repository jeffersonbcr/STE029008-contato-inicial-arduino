// C++ code
//

volatile int botao1 = 0;
int a0 = 0;
unsigned int scale_state = 0;
unsigned long m_voltz;
unsigned long v_voltz;
enum State_t
{
  WAIT = 0,
  ENTRADA = 1,
  V = 2,
  MV = 3,
  PRINT = 4
};

State_t state = WAIT;

void changeScale (){
  	scale_state = !scale_state;
}
void botao_1_isr()
{
  static unsigned long ultima_interrupcao = 0;
  static const unsigned long tempo_botao = 500;

  unsigned long agora = millis();
  if ((agora - ultima_interrupcao) >= tempo_botao)
  {
    Serial.println("interruption button 1");
    botao1 = 1;
    ultima_interrupcao = agora;
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  state = WAIT;
  
  attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, LOW);
}

void loop()
{

  noInterrupts();
  int b1 = botao1;
  botao1 = 0;
  interrupts();
  
  int b2 = digitalRead(3);
 
  switch (state)
  {
    case WAIT:
       if(b2 == 0){
          state = ENTRADA;
          attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, RISING);
       }
      break;
    case ENTRADA:
        a0 = analogRead(A0);
    	if(b1==1){
          changeScale();
          if(scale_state == 1){
              state = V;
          }
          else{
            state = MV;
          }
          attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, LOW);
        }
    	else{
            if(scale_state == 1){
                state = V;
            }
            else{
              state = MV;
            }
          attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, LOW);
    	}
    	
      break;
    case V:
        v_voltz = ( (float) a0) * ( (float) 5000000 / (float) 1023);
        v_voltz = v_voltz / 1000;
    	state = PRINT;      
    	attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, RISING);
      break;

    case MV:
        m_voltz = ( (long) a0) * ( (long) 5000000 / (long) 1023);
        m_voltz = m_voltz / 1000;
        state = PRINT;
    	attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, RISING);
      break;
    case PRINT:
        if(b2 ==1){
      		state = WAIT;
        }
    	else{
          if(scale_state == 1) {
              Serial.print("Valor em volts:");
              Serial.print(v_voltz/1000);
              Serial.print('.');
              Serial.println(v_voltz%1000);
              state = ENTRADA;
            }
          if (scale_state == 0) {
              Serial.print("Valor em millivolts:");
              Serial.println(m_voltz);
              state = ENTRADA;
            }
          delay(500);
        }
    	attachInterrupt(digitalPinToInterrupt(2), botao_1_isr, LOW);
      break;

    default:
      break;
  }
 
}