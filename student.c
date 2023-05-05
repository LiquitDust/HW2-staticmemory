#include <stdio.h>
#include <math.h>
#define MAX 10
float mem[2*MAX];
float angle,angle2,angle3,temp,temp2,magnitude;
int count=0;
int i,b,x;
void print()
{
   printf("You used Print() In Memory I have:\n");
   for(i=0;i<count;i +=2){     
     printf("%g+%gi\n",mem[i],mem[i+1]);             // re + im i  format 
   }  
}
void push(float re,float im)
{
    if(2*MAX<=count){                                    // 0 1 2 3 4   
        printf("You used Push() But Not Enough Space For %g+%gi \n",re,im);       
    }else{

        mem[count]=re;
        mem[count+1]=im;
        printf("Done %g+%gi added to system\n",mem[count],mem[count+1]);
        count +=2;
    }
}
void pop()
{
    if(count<=1){
        printf("You used Pop(), Memory is already empty\n");
    }else{

        printf("You used Pop() I cleared  %g+%gi \n",mem[count-2],mem[count-1]);
    count -=2;
    }
}
void print_polar(){
    printf("You used Print_polar() In Memory I have:\n");
   for(i=0;i<count;i +=2){
    angle  = 180/M_PI*fabsf((atanf(mem[i+1]/mem[i])));
    if(mem[i+1]>0 && mem[i]<0){
        angle = 180-angle;
    }if(mem[i+1]<0 && mem[i]<0){
        angle = 180+angle;
    }if(mem[i+1]<0 && mem[i]>0){
        angle = 360-angle;
    }
    if(mem[i+1] == 0){
        angle = 0;
        if(mem[i]<0){
            angle = 180;
        }
    }    
    if(mem[i] == 0){
        angle  = 90;
        if(mem[i+1]<0){
            angle = 270;
        }
    }
    if(mem[i]==0 && mem[i+1]==0){       ////////degisebilir
        angle = 0;
    }
    magnitude = powf(mem[i]*mem[i]+mem[i+1]*mem[i+1],0.5);
     printf("%g[%gdeg]\n",magnitude,angle);
   } 
}
void sort(){
    printf("Sorting done...\n");
    for(x=0;x<=count/2;x++){
    for(b=0;b<count-2;b+=2){                                  //2 1i  2 3i ; 
    
       if((mem[b]>mem[b+2])){
       temp=mem[b];      ///   
       mem[b]=mem[b+2];
       mem[b+2]=temp;    //switching imaginery values
       temp2=mem[b+1];
       mem[b+1]=mem[b+3];
       mem[b+3]=temp2;
      }
      if((mem[b]==mem[b+2]) && (mem[b+1]>mem[b+3]) ){
       temp=mem[b];      ///switching real values
       mem[b]=mem[b+2];
       mem[b+2]=temp;    //switching imaginery values
       temp2=mem[b+1];
       mem[b+1]=mem[b+3];
       mem[b+3]=temp2;
    }
    }
    }
}
void sort_polar(){
    printf("Sorting by polar done...\n");
    for(x=0;x<=count/2;x++){
    for(b=0;b<count-2;b+=2){                                  //  3 6i 8 9i ; 
    
       if(powf((mem[b]*mem[b]+(mem[b+1]*mem[b+1])),0.5) > powf(mem[b+2]*mem[b+2]+mem[b+3]*mem[b+3],0.5)){
       temp=mem[b];      ///switching real values
       mem[b]=mem[b+2];
       mem[b+2]=temp;    //switching imaginery values
       temp2=mem[b+1];
       mem[b+1]=mem[b+3];
       mem[b+3]=temp2;
      }
      angle2=(180/M_PI)*fabsf(atanf((mem[b+1]/mem[b])));
      if(mem[b+1]>0 && mem[b]<0){
        angle2=180-angle2;  //  x = x +2 
      }if(mem[b+1]<0 && mem[b]<0){
        angle2 = 180+angle2;
      }if(mem[b+1]<0 && mem[b]>0){
        angle2=360-angle2;
      }
      if(mem[b+1] == 0 ){
        angle2 = 0;
        if(mem[b]<0){
            angle2 = 180;
        } 
      }
      if (mem[b]==0 ){
        angle2 = 90;
        if(mem[b+1]<0){
            angle2 = 270;
        } 
      }
      if(mem[b]==0 && mem[b+1]==0){
        angle2 = 0;
      }
      angle3=(180/M_PI)*fabsf(atanf((mem[b+3]/mem[b+2])));
      if(mem[b+3]>0 && mem[b+2]<0){
        angle3=180-angle3;
      }if(mem[b+3]<0 && mem[b+2]<0){
        angle3= 180+angle3;
      }if(mem[b+3]<0 && mem[b+2]>0){
        angle3=360-angle3;
      }
      if(mem[b+3] == 0 ){
        angle3 = 0;
        if(mem[b+2]<0){
            angle3 = 180;
        } 
      }
      if (mem[b+2]==0 ){
        angle3 = 90;
        if(mem[b+3]<0){
            angle3 = 270;
        } 
      }
      if(mem[b+2]==0 && mem[b+3]==0){
        angle3 = 0;
      }
      if(powf((mem[b]*mem[b]+(mem[b+1]*mem[b+1])),0.5)==powf(mem[b+2]*mem[b+2]+mem[b+3]*mem[b+3],0.5) && ((angle2)>(angle3))){
       temp=mem[b];      ///switching real values
       mem[b]=mem[b+2];
       mem[b+2]=temp;    //switching imaginery values
       temp2=mem[b+1];
       mem[b+1]=mem[b+3];
       mem[b+3]=temp2;
    }
    }
    }
}