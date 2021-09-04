#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _etudiante {
  char *name;
  int hash;
} etudiante;

etudiante* new_student(char* name){
  int len=strlen(name);
  int hash=0;
  for(int i=0;i<len;i++){
    hash+=(43*name[i])%len;
  }
  etudiante *etu=malloc(sizeof(etudiante));
  etu->name=name;
  etu->hash=hash;
  return etu;
}

etudiante* shallow_copy(etudiante* stu){
  return stu;
}

etudiante* deep_copy(etudiante* stu){
  etudiante *etu=malloc(sizeof(etudiante));
  etu->name=stu->name;
  etu->hash=stu->hash;
  return etu;
}

void print_student(etudiante* stu){
  printf("%s, %d\n",stu->name,stu->hash);
}

void delete_student(etudiante* stu){
  free(stu);
}

void set_name(etudiante* stu,char* newName){
  int len=strlen(newName);
  int hash=0;
  for(int i=0;i<len;i++){
    hash+=(43*newName[i])%len;
  }

  stu->name=newName;
  stu->hash=hash;
}

void doStuffWithStudent(char* name){
  printf("welcome %s\n",name);

  etudiante *s = new_student(name);
  print_student(s);

  etudiante* s_deep = deep_copy(s);
  set_name(s_deep, "deep_student");

  print_student(s_deep);
  print_student(s);

  etudiante* s_shallow = shallow_copy(s);
  set_name(s_shallow, "shallow_student");

  print_student(s);
  print_student(s_deep);
  print_student(s_shallow);

  //free the students !
  delete_student(s);
  delete_student(s_deep);
  printf("\n");
}

int main() {

  char name1[40];
  char name2[40];
  scanf("%s", name1);
  scanf("%s", name2);

  doStuffWithStudent(name1);
  doStuffWithStudent(name2);
  
 
  return EXIT_SUCCESS;
}