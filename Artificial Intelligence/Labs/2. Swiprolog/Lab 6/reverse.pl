list_reverse([],[]).
list_reverse([H|T],L):-
list_reverse(T,R),append(R,[H],L).