//Rotary Encoder Example 00
int encoderPin1 = 2;
int encoderPin2 = 3;
 
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long tmp=0; 
double encoderValue1=0;
//long lastencoderValue = 0;
 
int lastMSB = 0;
int lastLSB = 0;
 
void setup() {
  Serial.begin (9600);
 
  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
 
  attachInterrupt(0, updateEncoder, CHANGE); //Interrrupt Pin D2
  attachInterrupt(1, updateEncoder, CHANGE); //Interrrupt Pin D3
 
}
 
void loop(){
  
  if (tmp != encoderValue) {
    if (encoderValue ==4){
      encoderValue1 +=0.5;
      encoderValue=0;
      Serial.println(encoderValue1);
      }
    if (encoderValue ==-4){
      encoderValue1-=0.5;
      encoderValue=0;
      Serial.println(encoderValue1);
      }    

    tmp = encoderValue;
  }

  
}
 
void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit
 
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
 
  lastEncoded = encoded; //store this value for next time
}
//----Tratto da: ----
//http://www.giuseppecaccavale.it/arduino/rotary-encoder-arduino/
//http://bildr.org/2012/08/rotary-encoder-arduino/
