#include <stdio.h>

#define max 50
int main()
{
char str[max],state='a';
int i;
printf("Enter the string to be checked: ");
scanf("%s",str);
for(i=0;str[i]!='\0';i++)
{
switch(state)
{
case 'a': if(str[i]=='0') state='b';
else if(str[i]=='1') state='a';
break;
case 'b': if(str[i]=='0') state='b';
 else if(str[i]=='1') state='c';
break;
case 'c': if(str[i]=='0') state='b';
else if(str[i]=='1') state='a';
break;
 }
}
if(state=='c') 
printf("\nString is accepted as it reached the final state %c at the end.",state);
else 
printf("\nString is not accepted as it reached %c which is not the final state.",state);
return 0;
}
