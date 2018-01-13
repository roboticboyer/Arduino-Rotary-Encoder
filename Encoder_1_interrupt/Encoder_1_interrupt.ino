int encoderPin1 = 2;
int encoderPin2 = 3;
 
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long tmp=0; 
long lastencoderValue = 0;
 
 double encoderValue1=0;
void setup() {
  Serial.begin (9600);
 
  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
 
  attachInterrupt(0, updateEncoder, CHANGE);
  //attachInterrupt(1, updateEncoder, CHANGE);


  Serial.println("Prova encoder...");
}
 
void loop(){
  
  if (tmp != encoderValue) {
    if (encoderValue ==2){
      if (encoderValue1<12){
      //Serial.print("debug: ");
      //Serial.println(encoderValue1);
      encoderValue1 +=0.5;
      Serial.println(encoderValue1);
      }
      encoderValue=0;
      }
    if (encoderValue ==-2 ){
      if (encoderValue1>0){
      //Serial.print("debug: ");
      //Serial.println(encoderValue1);
      encoderValue1-=0.5;
      Serial.println(encoderValue1);
      }
      encoderValue=0;
      }    

    tmp = encoderValue;
  }

  
}
 
void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit
 
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value
 
  if(sum == 0b1001 || sum == 0b0110) encoderValue ++;
  if(sum == 0b0011 || sum == 0b1100) encoderValue --;
 
  lastEncoded = encoded; //store this value for next time
}
//----Tratto da: ----
//http://www.giuseppecaccavale.it/arduino/rotary-encoder-arduino/
//http://bildr.org/2012/08/rotary-encoder-arduino/
