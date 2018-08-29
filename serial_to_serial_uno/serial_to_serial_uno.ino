int phy_addr;
int reg_addr;
int data;
bool swich = false;

void update_leds(){
    int s4,s5,s6,s7;
    s4 = digitalRead(4);
    s5 = digitalRead(5);
    s6 = digitalRead(6);
    s7 = digitalRead(7);
    
    if(s4 == HIGH)digitalWrite(10,HIGH);
    else digitalWrite(10,LOW);
    if(s5 == HIGH)digitalWrite(11,HIGH);
    else digitalWrite(11,LOW);
    if(s6 == HIGH)digitalWrite(12,HIGH);
    else digitalWrite(12,LOW);
    if(s7 == HIGH)digitalWrite(13,HIGH);
    else digitalWrite(13,LOW);
}

void setup() {
   phy_addr = 50;
   Serial.begin(9600);
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(4,INPUT_PULLUP);
   pinMode(5,INPUT_PULLUP);
   pinMode(6,INPUT_PULLUP);
   pinMode(7,INPUT_PULLUP);
   
}

void loop() {

    //update_leds();
    
    while(Serial.available()<6){}
  
    byte b1 = Serial.read();
    byte b2 = Serial.read(); 
    byte b3 = Serial.read();
    byte b4 = Serial.read();
    byte b5 = Serial.read();
    byte b6 = Serial.read();
    
  
    phy_addr = (b1*256)+b2;
    reg_addr = (b3*256)+b4;
    data = (b5*256)+b6;
   
    if(phy_addr == 50)
    {
      if(reg_addr<128)
      {
        switch(data)
        {
          case 0:
            digitalWrite(13,LOW);
            digitalWrite(12,LOW);
            digitalWrite(11,LOW);
            digitalWrite(10,LOW);
            break;
          case 1:
            digitalWrite(13,HIGH);
            digitalWrite(12,LOW);
            digitalWrite(11,LOW);
            digitalWrite(10,LOW);
            break;
          case 2:
            digitalWrite(13,LOW);
            digitalWrite(12,HIGH);
            digitalWrite(11,LOW);
            digitalWrite(10,LOW);
            break;
          case 3:
            digitalWrite(13,HIGH);
            digitalWrite(12,HIGH);
            digitalWrite(11,LOW);
            digitalWrite(10,LOW);
            break;
          case 4:
            digitalWrite(13,LOW);
            digitalWrite(12,LOW);
            digitalWrite(11,HIGH);
            digitalWrite(10,LOW);
            break;
          case 5:
            digitalWrite(13,HIGH);
            digitalWrite(12,LOW);
            digitalWrite(11,HIGH);
            digitalWrite(10,LOW);
            break;
          case 6:
            digitalWrite(13,LOW);
            digitalWrite(12,HIGH);
            digitalWrite(11,HIGH);
            digitalWrite(10,LOW);
            break;
          case 7:
            digitalWrite(13,HIGH);
            digitalWrite(12,HIGH);
            digitalWrite(11,HIGH);
            digitalWrite(10,LOW); 
            break;
          case 8:
            digitalWrite(13,LOW);
            digitalWrite(12,LOW);
            digitalWrite(11,LOW);
            digitalWrite(10,HIGH);
            break;
          case 9:
            digitalWrite(13,HIGH);
            digitalWrite(12,LOW);
            digitalWrite(11,LOW);
            digitalWrite(10,HIGH);
            break;
          case 10:
            digitalWrite(13,LOW);
            digitalWrite(12,HIGH);
            digitalWrite(11,LOW);
            digitalWrite(10,HIGH);
            break;
          case 11:
            digitalWrite(13,HIGH);
            digitalWrite(12,HIGH);
            digitalWrite(11,LOW);
            digitalWrite(10,HIGH);
            break;
          case 12:
            digitalWrite(13,LOW);
            digitalWrite(12,LOW);
            digitalWrite(11,HIGH);
            digitalWrite(10,HIGH);
            break;
          case 13:
            digitalWrite(13,HIGH);
            digitalWrite(12,LOW);
            digitalWrite(11,HIGH);
            digitalWrite(10,HIGH);
            break;
          case 14:
            digitalWrite(13,LOW);
            digitalWrite(12,HIGH);
            digitalWrite(11,HIGH);
            digitalWrite(10,HIGH);
            break;
          case 15:
            digitalWrite(13,HIGH);
            digitalWrite(12,HIGH);
            digitalWrite(11,HIGH);
            digitalWrite(10,HIGH);
            break;
        }
      }else{
        byte b1,b2,b3,b4;
        b1 = Serial.write(digitalRead(13));
        b2 = Serial.write(digitalRead(12));
        b3 = Serial.write(digitalRead(11));
        b4 = Serial.write(digitalRead(10));
        delay(50);
      }
   }
}
    

