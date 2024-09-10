permutation([],[]).
permutation(L,[X|P]):-
del(X,L,L1),
permutation(L1,P).