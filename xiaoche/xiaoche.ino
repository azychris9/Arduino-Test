void setup()
{
   pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(3,OUTPUT);
    Serial.begin(9600);
}
int inputstr = 0;

void loop()
{
  if(Serial.available() > 0)
    {
      inputstr = Serial.read();
      switch(inputstr)
      {
        case 'f':
          forward();
          break;
        case 's':
          stop();
          break;
        case 'l':
          left();
          break;
        case 'r':
          right();
          break;
        case 'b':
          backward();
          break;
        default:
      break;
        
      }
    }
}

void backward()
{
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);
   digitalWrite(10,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(3,HIGH);
  digitalWrite(8,HIGH);
}
void forward()
{
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(10,LOW);
   digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
}
void stop()
{
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
}
void left()
{
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(9,LOW);
   digitalWrite(10,HIGH);
   digitalWrite(13,HIGH);
   digitalWrite(3,HIGH);

}
void right()
{
   digitalWrite(9,HIGH);
   digitalWrite(10,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(8,HIGH);

}
