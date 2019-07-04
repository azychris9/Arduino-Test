void setup()
{
	pinMode(7,OUTPUT);
  	pinMode(8,OUTPUT);
  	pinMode(12,OUTPUT);
  	pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  
  Serial.begin(9600);
}
int inputstr = 0;
void loop()
{   
  if(Serial.available() > 0)
     {
      digitalWrite(2,LOW);
      digitalWrite(1,HIGH);
      digitalWrite(0,HIGH);
      inputstr = Serial.read();
      inputstr = inputstr - '0';
      do_something(7,which_one(inputstr,0));
      do_something(8,which_one(inputstr,1));
      do_something(12,which_one(inputstr,2));
      do_something(13,which_one(inputstr,3));
     }
}
int which_one(int a,int b)
{
  int out;
    out = (a>>b)&1;//位运算每一位
	return out;
}
void do_something(int a,int b)
{
  if(b == 1)
    digitalWrite(a,HIGH);
  else
    digitalWrite(a,LOW);
}
