#include <Keypad.h>
const int ROWS =4, COLS =3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowpins[ROWS] = {9,8,7,6};
byte colpins[COLS] = {5,4,3};

Keypad keypad = Keypad(makeKeymap(keys),rowpins,colpins,ROWS,COLS);

char temp[5];
int total = 0;
char onkey1[5]={'1','5','5','5','5'};//on password floor 1
char onkey2[5]={'2','5','5','5','5'};//off password floor 1
char offkey1[5]={'1','0','0','0','0'};//on password floor 2
char offkey2[5]={'2','0','0','0','0'};//off password floor 2
const int LED1=11;//floor_one 
const int LED2=2;//floor_two
int count1=0;
int count2=0;
int flag1=0;
int flag2=0;
void setup()
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}
void loop()
{
      char key = keypad.getKey();
      if(key!= NO_KEY)
      {
        if(key=='1' || flag1==1)
        {
        flag1=1;
        if(total<4)
        {
          temp[total]=key;
          total++;
        }
        else
        {
          temp[total]=key;
          total++;
          bool checkonkey1 = 1;
          bool checkoffkey1= 1;
          for(int i =0;i<5;i++)
          {
            if(temp[i]!=onkey1[i])
            {
              checkonkey1 = 0;
            }
          }
          for(int i =0;i<5;i++)
          {
            if(temp[i]!=offkey1[i])
            {
              checkoffkey1 = 0;
            }
          }
      
          if(checkonkey1)
          {				
            digitalWrite(LED1, HIGH);  
            Serial.println(1);
          }
          if(checkoffkey1)
          {				
            digitalWrite(LED1, LOW);	
            Serial.println(2);		
          }
          total=0;
          delay(1000);
        }
        count1=count1+1;
        if(count1==5){
          flag1=0;    
          count1=0;
        }
      }
      
      if(key=='2' || flag2==2)
        {
        flag2=2;
        if(total<4)
        {
          temp[total]=key;
          total++;
        }
        else
        {
          temp[total]=key;
          total++;
          bool checkonkey2 = 1;
          bool checkoffkey2= 1;
          for(int i =0;i<5;i++)
          {
            if(temp[i]!=onkey2[i])
            {
              checkonkey2 = 0;
            }
          }
          for(int i =0;i<5;i++)
          {
            if(temp[i]!=offkey2[i])
            {
              checkoffkey2 = 0;
            }
          }
      
          if(checkonkey2)
          {        
            digitalWrite(LED2, HIGH);  
            Serial.println(3);
          }
          if(checkoffkey2)
          {       
            digitalWrite(LED2, LOW);
            Serial.println(4);      
          }
          total=0;
          delay(1000);
        }
        count2=count2+1;
        if(count2==5){
         flag2=0;
         count2=0;    
        }
      }
      }
}
