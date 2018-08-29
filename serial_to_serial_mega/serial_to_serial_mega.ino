int ledpin = 13;
int phy_addr = 10;
int reg_addr;
int data;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(ledpin,OUTPUT);
  pinMode(2,INPUT);
  pinMode(8,OUTPUT);
  
  Serial.flush();
  Serial1.flush();
}

void loop() {
    
    digitalWrite(8,HIGH);
    Serial.println("Enter phy_addr");
    while(Serial.available()==0){} 
    phy_addr = Serial.parseInt();
  
    Serial.println("Enter reg_addr");
    while(Serial.available()==0){} 
    reg_addr = Serial.parseInt();
  
    Serial.println("Enter pattern of led on's");
    while(Serial.available()==0){} 
    data = Serial.parseInt();
  
    Serial.println();

  switch(phy_addr)
  {
    case 10:
         if(data == 1) digitalWrite(ledpin,HIGH);
         else digitalWrite(ledpin,LOW);
         break;

   case 50:
        Serial1.write(phy_addr/256);
        Serial1.write(phy_addr%256);
        Serial1.write(reg_addr/256);
        Serial1.write(reg_addr%256);
        Serial1.write(data/256);
        Serial1.write(data%256);
        delay(50);

        if(reg_addr>127)//read status of led's
        {
          while(Serial1.available()<4){}
          byte b1 = Serial1.read();
          byte b2 = Serial1.read();
          byte b3 = Serial1.read();
          byte b4 = Serial1.read();
          Serial.println(b1);
          Serial.println(b2);
          Serial.println(b3);
          Serial.println(b4);
        }
        break;
        

  }

}
