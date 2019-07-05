#include<stdio.h>
#include<string.h>
#define SIZE 28
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}

struct Morse_code{
    char character;
    char code[6];
};
struct Morse_code morse1[SIZE] = {
    'a', ".-",
    'b', "-...",
    'c', "-.-.",
    'd', "-..",
    'e', ".",
    'f', "..-.",
    'g', "--.",
    'h', "....",
    'i', "..",
    'j', ".---",
    'k', "-.-",
    'l', ".-..",
    'm', "--",
    'n', "-.",
    'o', "---",
    'p', ".--.",
    'q', "--.-",
    'r', ".-.",
    's', "...",
    't', "-",
    'u', "..-",
    'v', "...-",
    'w', ".--",
    'x', "-..-",
    'y', "-.--",
    'z', "--..",
    ' ',"@@",
    '\n',"&&",
};//'a-z'morse code

int which_one(char str)
{
  int a ;
  if(str == ' '){
    a == 26;
  }
  else if(str == '\n'){
    a == 27;
  }
  else{
    a = str - 'a';
  }
  return a;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
String inputstr;
String outputstr;
Morse morse(13);//13瑙掔爜

void loop() {
  // put your main code here, to run repeatedly:
  inputstr = Serial.readString();
  int i,j,b;
  for(i = 0;i < inputstr.length();i++)
  {
    int b = which_one(inputstr[i]);//纭畾杩欎竴椤规槸閭ｄ釜瀛楁瘝
    if(b == 26)
      morse.w_space();//绌烘牸鍋滈】
    else if(b == 27)
      morse.w_space();//鎹㈣鍋滈】
    else
    {
      outputstr = morse1[b%SIZE].code;
      for(int j = 0;j < outputstr.length();j++)
      {
       if(outputstr[j] == '.')
          morse.dot();
       else if(outputstr[j] == '-')
          morse.dash();
      }
      morse.c_space();
    }//'a-z'瀛楁瘝morse鐮侀棯鐑?
  }

}