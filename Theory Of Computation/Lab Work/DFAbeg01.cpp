// TOC Lab 2: Implement a DFA for L = { set of all strings over {0,1} such that
// string start with 01
#include<stdio.h>

enum states { q0, q1, qf,qd};
enum states delta(enum states, char);

int main()
{
	char input[20];
	enum states curr_state = q0;
	int i =0;
	
	printf("\n Enter a binary string\t");
	gets(input);
	char ch = input[i];
	while( ch !='\0')
	{
	    curr_state = delta(curr_state,ch);
		ch = input[++i];
  	}
  	
	if(curr_state == qf)
	   printf("\n The string %s is accepted.",input);
	else 
	    printf("\n The string %s is not accepted.",input);	    
		
   return 0;			
}


enum states delta(enum states s, char ch)
{
       enum states curr_state;
	   switch(s)
		{
			case q0:
				if(ch=='0')
				   curr_state = q1;
				else
				   curr_state = qd;
				break;
			case q1:
				if(ch=='1')
				   curr_state = qf;
				else
				   curr_state = qd;
				break;
			case qf:
				if(ch=='0')
				   curr_state = qf;
				else
				   curr_state = qf;
				break;
			case qd:
				if(ch=='0')
				   curr_state = qd;
				else
				   curr_state = qd;
				break;
		}	
	return curr_state;
}
