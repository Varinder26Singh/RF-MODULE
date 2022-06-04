#include <VirtualWire.h>
char t;
char *data;
void setup() 
{
    pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT);   
  pinMode(9,OUTPUT);   
  pinMode(11,OUTPUT);  
  Serial.begin(9600);
    vw_set_tx_pin(3);
    vw_setup(2000);
    pinMode (5, LOW);
    pinMode (6, LOW);
    pinMode (9, LOW);
    pinMode (11, LOW); 
}

void loop()
{
   if(Serial.available()){ 
  t = Serial.read();
  Serial.println(t);
}
  if(t == 'F')   // forward
  {
    data="f";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();    
    digitalWrite(9,HIGH);
      digitalWrite(5,HIGH);
  }
  else if(t =='B')  // backward
  {
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    digitalWrite(6,HIGH);
    digitalWrite(11,HIGH);
  }
  else if(t == 'L'){   // left
    data="l";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();      
  digitalWrite(9,HIGH);
}
  else if(t == 'R'){  // right
      data="r";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
    digitalWrite(5,HIGH);
  }
  else if(t == 'S'){  //stop
      data="s";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(11,LOW);
  }
}
