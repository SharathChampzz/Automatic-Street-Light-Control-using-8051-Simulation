#include<reg51.h>
sbit trigpin = P2^6;
sbit echopin = P2^7;
sbit led1 = P1^5;
sbit led2 = P1^7;

void delay(unsigned int z);
unsigned int distance,i;
void main(){
      echopin=1;
      led1=0;
      led2=0;
      trigpin=0;
      echopin=1;

      for(i=0;i<20000;i++);
      TMOD=0x01;
      TH0=0x00;
      TL0=0x00;


      while(1)
      {
            trigpin=1;
            for(i=0;i<=10;i++);
            trigpin=0;
            while(echopin==0);
            TR0=1;
            while(echopin==1);
            TR0=0;

            distance=TH0<<B;
            distance=distance+TL0;
            distance=distance/5;
            TH0=0x00;
            TL0=0x00;


            for(i=0;i<=20000;i++);

            if(distance<25)
            {
                led1=1; // Consider this, Car is Nearby
            }
            else
            {
                led1=0;
            }

            if(distance>50)
            {
                led2=1; // Just Ignore
            }

            else
            {
                led2=0;
            }
      }
}                                                             


void delay(unsigned int z)
{
    unsigned int p,q;
    for(p=0;p<z;p++)//repeat for 'z' times
    {
      for(q=0;q<1375;q++); //repeat for 1375 times
    }
}                   