#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float moyenne(int i,float*arr){
  if(i==14){
    return arr[i]/15;
  }else{
    return arr[i]/15+moyenne(i+1,arr);
  }
}

void swap(float*a,float*b){
  float tmp=*a;
  *a=*b;
  *b=tmp;
}

void inverse(int i,float* arr){
  if(i>7){
    return;
  }
  swap(&arr[i],&arr[14-i]);
  inverse(i+1,arr);
}

int main() {

  float change[15];
  for(int i=0;i<15;i++){
    scanf("%f",&change[i]);
  }
  
  // printf("")
   printf("moyenne: %.3f\ninversion:\n",moyenne(0,change));

   inverse(0,change);

   for(int i=0;i<15;i++){
    printf("%.2f\n",change[i]);
  }

  return EXIT_SUCCESS;
}