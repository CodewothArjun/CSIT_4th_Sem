fibo(0,1).
fibo(1,1).
fibo(N,X):-
N>1,
N1 is N-1,
N2 is N-2,
fibo(N1,F1),
fibo(N2,F2),
X is F1+F2.