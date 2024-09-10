list([8,4]).
average_easy(List,Avg):-
sum_(List,Sum),
length_(List,Length),
Avg is Sum/Length.
sum_([],0).
sum_([H|T],Sum):-
sum_(T,Temp),
Sum is Temp + H.
length_([],0).
length_([_|B],L):-
length_(B,Ln),
L is Ln+1.
main:-
list(X),
average_easy(X,Ans),
writeln((X,Ans)).