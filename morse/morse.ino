#include <Morse.h>
#include<stdio.h>
#include<string.h>
#define SIZE 28


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
Morse morse(13);//13角码

void loop() {
  // put your main code here, to run repeatedly:
  inputstr = Serial.readString();
  int i,j,b;
  for(i = 0;i < inputstr.length();i++)
  {
    int b = which_one(inputstr[i]);//确定这一项是那个字母
    if(b == 26)
      morse.c_space();//空格停顿
    else if(b == 27)
      morse.w_space();//换行停顿
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
    }//'a-z'字母morse码闪烁
  }

}
