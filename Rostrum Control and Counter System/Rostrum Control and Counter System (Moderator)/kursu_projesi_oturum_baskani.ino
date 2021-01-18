#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int latchPin = 8;
int latchPin1 = 9;
int latchPin2 = 7;
int latchPin3 = 6;

int but= A0;
int but1= A2;
int but2=A1;
int but3=A3;

int butb;
int but1b;
int but2b;
int but3b;

 int butbas=0;
 int but1bas=0;
 int but3bas=0;
 
 int basma= 0;
  
  int sayac =-1;
int sayacas;

int birler;
int i1;
int onlar;
int acilis=0;

int sayi1=0;
int sayi2=0;
  
int clockPin = 12;
int dataPin = 11;
byte dataArrayRED[10];
byte dataArrayGREEN[10];



       void setup() {

 lcd.init();
  lcd.backlight();

  
lcd.setCursor(2,0);

lcd.print(" Konusmaci");


lcd.setCursor(1,1);

lcd.print("beklenmektedir.");

}

        void loop() {

  butb=digitalRead(but);
  but1b=digitalRead(but1);
  but3b=digitalRead(but3);


//artırma bölümü...
if(but1b==HIGH and but1bas==0 and butbas==0){

but1bas=1;



  }
 
 
  

  
else if(but1b==LOW and but1bas==1 and butbas == 0 ){
lcd.clear();
sayac=sayac+5;
  if(sayac >90){
    
    sayac=89;

    
    
    }
    
  
  lcd.setCursor(2,0);

lcd.print(" Konusmaci");


lcd.setCursor(1,1);

lcd.print("beklenmektedir.");

delay(100);
but1bas=0;
} 








//azaltma bölümü...
if(but3b==HIGH and but3bas==0 and butbas==0){

but3bas=1;



  }
 
 
  

  
else if(but3b==LOW and but3bas==1 and butbas == 0 ){
lcd.clear();
sayac=sayac-5;
  if(sayac < 0){
    
    sayac=-1;

    
    
    }

  lcd.setCursor(2,0);

lcd.print(" Konusmaci");


lcd.setCursor(1,1);

lcd.print("beklenmektedir.");

but3bas=0;

}





//başlatma bölümü....

  if(sayac >= 4){
 
if(butb==HIGH and butbas==0 and but1bas ==0){


butbas=1;



  }
 
 
  

  
if(butb==LOW and butbas == 1 and but1bas ==0){



lcd.clear();


butbas=0;

if(sayac>=4 ){
  
}
dk();


  basma =0;
  sayac=-1;


  
  lcd.clear();

  lcd.setCursor(2,0);
lcd.print(" Konusmaci");

 lcd.setCursor(1,1);
lcd.print("beklenmektedir.");




}

}

}
  

 void dk(){
      for(sayac;sayac>=0;sayac)
        {
     
if(basma == 1){
  
  sayac =0;
 
  break;
  }

      
      
     onlar=sayac/10;
     
     birler= sayac-(onlar*10) ;

if(onlar>=1){



  
  for(onlar;onlar>=1;onlar){
    
    if(basma == 1){
  onlar=0;
  
  break;
  }
  
lcd.setCursor(0,0);
lcd.print("  kalan sure =");

 lcd.setCursor(6,1);
lcd.print(onlar);
  
 
   
for(birler;birler>=0;birler--){

if(basma == 1){
  birler=0;
  
  break;
  }
 lcd.setCursor(7,1);
lcd.print(birler);





onlar--; 




if(sayac>0){

sayac--;

  }
 else{
  sayac=-1;

  }
  
 sn();
  
   
 




  }
 

  }
   }



else if(onlar==0){
  lcd.clear();


sayac=sayac-1;
    
  lcd.setCursor(0,0);
lcd.print("  kalan sure =");






  for(sayac;sayac>=0;sayac--){

if(basma==1){
 
 sayac =0;
  
}

   lcd.setCursor(7,1);
lcd.print(sayac+1);

sn();
  


  }




  

  




 
  
  }


 

   
  
     }
   

 
 
 
      }
  
  
  
  









//SANİYE HESABI

void sn()
{
  int sayac1=sayac+1;
          int onlar1=sayac1/10;
     
    int birler1= sayac1-(onlar1*10) ;
    
     
int i;




 for( i1=59; i1>=1; i1){

if(basma == 1){
  i1 =0;
  
  break;
  }


   if(i1>9){
    i1=i1/10;
    
    
    
    lcd.setCursor(8,1);
lcd.print(":");

 lcd.setCursor(9,1);
lcd.print(i1);
   
    }
   
 
  
    else{
      i1--;



  
   

 lcd.setCursor(9,1);
lcd.print(i1);
    
      
      
      }
     
     


   
      


    for( i=9;i>=0;i--){

if(basma == 1){
  i =0;
  
  break;
  
}


 lcd.setCursor(10,1);
lcd.print(i);




sls();



}
 


  

   
      }
      

   
}





//SALİSE HESABI

void sls(){
  

  
   for(int i2=99; i2>=1; i2){

if(basma==1 ){
  
  i2=0;
break;
}
      


   if(i2>9){
    i2=i2/10;
    
    }
   
 
  
    else{
      i2--;
 
      }
     
   


    for( int i3=9;i3>=0;i3--){

  if(basma==1 ){
  i3=0;
break;
 



 }

  slssls();
  
    
      
      }
      

   
}

  
  }








//SALİSENİN SALİSESİ HESABI

void slssls(){
  
 but2b=digitalRead(but2);
  
   for(int i2=99; i2>=1; i2){

if(but2b==HIGH ){

  i2=0;
  basma=1;
   
break;
}
      


   if(i2>9){
    i2=i2/10;
    
    }
   
 
  
    else{
      i2--;
 
      }
     
   


  
  delayMicroseconds(1004);  
  
    
      
      }
      

   
}
  
