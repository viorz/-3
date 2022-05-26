#include <stdio.h> 
#include <cstring> 
#include <fstream>
using namespace std;

main () { 
FILE *file; 
struct perechen { 
char name[60]; 
char designator[30]; 
int qty; 
}; 
struct perechen element[10000]; 
struct perechen nextelement[10000]; 
int i=0; 
int j=0; 
int k=0; 
int n=1; 
int a=1;
int b=1;
char ch;
char strok[4];
char tabu;

printf ("Sozdayte fail '1.txt' so spiskom elementov v vvide\n");
printf ("C1	GRM155R71C104KL	1\n");
printf ("C2	GRM155R71C104KL	1\n");
printf ("C3	GRM155R71C104KL	1\n");
printf ("C4	ATC600L5R6CT200	1\n");
printf ("C5	GRM155R71C104KL	1\n");
printf ("C6	GRM155R71C104KL	1\n");
system("pause");
//--------открытие файла

file = fopen("1.txt", "r"); 
if (file == NULL) {
	printf ("Error\n");
}
else {
	printf ("Fail open\n");
}


//------------считывание фала
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
while (feof (file) == 0) 
{ 
ch=fgetc(file);
for (k = 0; ch!='\t' && feof (file) == 0; k++)
	{
		element[i].designator[k]=ch;
//		printf("%c", ch);
		ch=fgetc(file);
	}
k=0;
//printf ("\t");
ch=fgetc(file);

for (k = 0; ch!='\t' && feof (file) == 0; k++)
	{
		element[i].name[k]=ch;
//		printf("%c", ch);
		ch=fgetc(file);
	}
k=0;
//printf ("\t");
ch=fgetc(file);

	strok[0]=0;				//обнуление массива
	strok[1]=0;
	strok[2]=0;
	strok[3]=0;

for (k = 0; ch!='\n' && feof (file) == 0; k++)

	
	{
		strok[k]=ch-48;		//перевод числа из кодировки ASCII

		ch=fgetc(file);
		a=a*10;				//переменная разрядов
	}
	
	
	n=strok[0]*a/10 + strok[1]*a/100 +  strok[2]*a/1000 +  strok[3]*a/10000;		//перевод строки в число
	element[i].qty=n;

	a=1;
k=0;
i++;





}
k=0;
n=i;
i=0;


// Печать на экран считанных данных
/*
while (i<n) 
{
	for (int k = 0; k<sizeof(element[i].designator); k++)
	{
	printf("%c", element[i].designator[k]);
	}
	printf("\t");
	
	for (int k = 0; k<sizeof(element[i].name); k++)
	{
	printf("%c", element[i].name[k]);
	}
	printf("\t");
	
	

	printf("%u", element[i].qty);

	printf("\n");



	
i++;

}*/

i=n;


//-------------группировка элементов
while (j<i) 
{ 


if (strcmp(element[j].name, element[j+1].name)==0)
{
	n=element[j].qty;
	strcpy(nextelement[k].designator, element[j].designator);  
	strcpy(nextelement[k].name,element[j].name); 
	while (strcmp(element[j].name, element[j+1].name)==0)
	{
	n=n+element[j+1].qty;
	j++;
	
	}
	if (n==2)
	{
		strcat(nextelement[k].designator, ","); 
	}
	else
	{
		strcat(nextelement[k].designator, "..");
	}
	strcat(nextelement[k].designator, element[j].designator); 
	nextelement[k].qty = n; 



	k++;
	j++;
}
else
{
	n=element[j].qty;
	strcpy(nextelement[k].name,element[j].name); 
	strcpy(nextelement[k].designator, element[j].designator); 
	nextelement[k].qty = n; 
	j++;
	k++;

}




}
//-----------вывод на экран перечня элементов
n=k;
/*k=0;
printf ("%u\n", n); 
while (k<n) 
{
	printf("%s %s %u\n", nextelement[k].name, nextelement[k].designator, nextelement[k].qty);
	k++; 
}*/

fclose(file);



//-------------запись в файл
file = fopen("2.txt", "w"); 
if (file == NULL) {
	printf ("Error write\n");
}
else {
	printf ("Finish\n");
}
k=0;
while (k<n) 
{

	fprintf(file, "%s\t%s\t%u\n", nextelement[k].designator, nextelement[k].name, nextelement[k].qty); 
	fflush(file); 
	k++; 
}
fclose(file);
system("pause");
}
