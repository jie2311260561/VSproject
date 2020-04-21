#ifndef MANAGEMEMENT_H
#define MANAGEMEMENT_H
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

struct employee
{
	int num;
	char name[10];
	char sex;  
	int age;
	char doc[30];
	int wage;
	char days[30];
	long int tel;
}em[100];        /*定义一个结构体*/

void menu();
void input();
void save(int);
void display();
void del();
void add();
void search();
void search_num();
void search_doc();
void search_tel();
void modify();  /*定义各函数*/

#endif
