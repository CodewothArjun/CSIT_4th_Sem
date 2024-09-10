greatest():-
write("Enter the first number : "),
read(X),
write("Enter the second number : "),
read(Y),
write("Enter the third number : "),
read(Z),
maxi(X,Y,Z).
maxi(X,Y,Z):-
Y>Z,X>Y,
write("The maximum number is : "),write(X).
maxi(X,Y,Z):-
Z>X,X>Y,
write("The maximum number is : "),write(Z).
maxi(X,Y,Z):-
write("The maximum number is : "),write(Y).