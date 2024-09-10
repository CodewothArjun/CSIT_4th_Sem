cube:-
write('Enter a number : '),read(X),
process(X).
process(stop):- !.
process(N):-
C is N*N*N,
write('Cube of '),write(N),write(' is '),write(C),nl,
cube.