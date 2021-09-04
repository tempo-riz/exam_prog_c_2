#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_strlen(char* str){
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  return i;
}

void hamming_distance(char*s1,char*s2){
  int len1=my_strlen(s1);
  if(len1!=my_strlen(s2)){
    
    printf("Distance %s - %s: Impossible\n",s1,s2);
    return;
  }

  int cnt=0;
  for(int i;i<len1;i++){
    if(s1[i]!=s2[i]){
      cnt++;
    }
  }
  printf("Distance %s - %s: %d\n",s1,s2,cnt);
}

int main() {

  char str0[40];
  char str1[40];
  char str2[40];
  scanf("%s", str0);
  scanf("%s", str1);
  scanf("%s", str2);

  hamming_distance(str0,str1);
  hamming_distance(str0,str2);
  hamming_distance(str1,str2);
  printf("\n");

  return EXIT_SUCCESS;
}