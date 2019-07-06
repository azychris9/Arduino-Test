void setup()
{
	pinMode(2,OUTPUT);
  	pinMode(3,OUTPUT);
  	pinMode(4,OUTPUT);
  	pinMode(5,OUTPUT);
  		pinMode(6,OUTPUT);
  		pinMode(7,OUTPUT);
  			pinMode(8,OUTPUT);
  			pinMode(9,OUTPUT);
  			pinMode(10,OUTPUT);
  			pinMode(11,OUTPUT);
  
  Serial.begin(9600);
}
int inputstr = 0;
String incom;
void loop()
{   
  if(Serial.available() > 0)
     {
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
   	 digitalWrite(9,LOW);
    	digitalWrite(10,LOW);
    	digitalWrite(11,LOW);
      incom = Serial.readString();
    for(int i = 0;i < 4;i++)
    	{
      		inputstr = incom[i];
      		work(inputstr,i);
    	}
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
void work(int inputstr,int b)
{
      inputstr = inputstr - '0';
      do_something(2,which_one(inputstr,0));
      do_something(3,which_one(inputstr,1));
      do_something(4,which_one(inputstr,2));
      do_something(5,which_one(inputstr,3));
  		digitalWrite(11 - b,HIGH);
}