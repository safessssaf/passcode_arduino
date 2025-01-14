#include <Keypad.h>
#include <LiquidCrystal.h>


const byte Y_row=4;
const byte X_col=4;
byte Y_pins[Y_row]={13,12,11,10};
byte X_pins[X_col]={9,8,7,6};
char KEYS[Y_row][X_col]={
{'1', '2','3','Y'},
{'4', '5','6','l'},
{'7', '8','9','o'},
{'*', '0','#','l'},
};
Keypad keypad = Keypad(makeKeymap(KEYS),Y_pins,X_pins,Y_row,X_col);
const int rs=A4,E=A5,d0=5,d1=4,d2=3,d3=2,d4=A0,d5=A1,d6=A2,d7=A3;
LiquidCrystal lcd(rs,E,d0,d1,d2,d3,d4,d5,d6,d7);

String correct_password= "742333";
String key_entered="";
int r=A0;
int g=A1;
int b=A2;
int motor=5;





void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(r, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(motor, OUTPUT);
}
  
void loop()
{   
   char key= keypad.getKey();

   if(key)
   {
      if(key=='*')
      {
          lcd.clear(); 

          key_entered="";
          lcd.print("password");
          lcd.setCursor(0, 1);
          lcd.print("resting");
          delay(400);
          lcd.clear();
          delay(400);
          lcd.print("password");
          lcd.setCursor(0, 1);
          lcd.print("resting");
          delay(400);
          lcd.clear();

      }
      else if (key=='#')
      {   
      lcd.clear();
      if(key_entered == correct_password)
      { 
        lcd.print("access");
        lcd.setCursor(0, 1);
        lcd.print("granted");
        delay(400);
        lcd.clear();
        delay(400);
        lcd.print("access");
        lcd.setCursor(0, 1);
        lcd.print("granted");
        delay(400);
        lcd.clear();
    }
    else
    {
      lcd.clear();
      lcd.print("access");
      lcd.setCursor(0, 1);
      lcd.print("denied");
      delay(400);
      lcd.clear();
      delay(400);
      lcd.print("access");
      lcd.setCursor(0, 1);
      lcd.print("denied");
      delay(400);
      lcd.clear();
    } 
    key_entered="";
    }
    else
    {
      lcd.clear();
      key_entered+=key;
      lcd.print(key_entered);
    }
  
  }

}
