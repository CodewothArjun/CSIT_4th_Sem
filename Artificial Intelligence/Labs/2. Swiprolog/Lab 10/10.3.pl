greatest:-
write('Enter the first number : '),
read(X),
write('Enter the second number : '),
read(Y),
write('Enter the third number : '),
read(Z),
maxi(X,Y,Z).
maxi(A,B,C):-
A=<B,B=<C,
write('The maximum number is : '),write(C).
maxi(A,B,C):-
A>=B,A>=C,
write('The maximum number is : '),write(A).
maxi(A,B,C):-
write('The maximum number is : '),write(B).