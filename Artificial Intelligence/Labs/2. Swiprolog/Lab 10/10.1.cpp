#include<iostream.h>
#include<swi-prolog.h>
using namespace std;
void main()
{
    //provides the prolog environment with the file "likes.pl"
    PlEngine("likes.pl");
    //likes(X,Kate);
    PlTermv av(2);
    av[1]="Kate";
    while(q.next_solution())
    {
        cout<<(char *)av[0]<<endl;
    }
}
