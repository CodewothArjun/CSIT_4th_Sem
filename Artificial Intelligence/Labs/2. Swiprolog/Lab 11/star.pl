sqaure(1):-
write('*****').
square(X):-
X>=1,
write('*****'),
nl,
square(X-1).
