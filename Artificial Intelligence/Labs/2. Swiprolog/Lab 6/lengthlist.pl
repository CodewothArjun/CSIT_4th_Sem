list_length([],0).
list_length([_|T],L):-list_length(T,L1),L is L1+1.
