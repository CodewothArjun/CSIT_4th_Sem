greatest(X,A,B,C):-
A=<B,B=<C,
X is C.
greatest(X,A,B,C):-
A>=B,A>=C,
X is A.
greatest(X,A,B,C):-
X is B.