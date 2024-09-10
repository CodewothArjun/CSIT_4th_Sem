delt(X,[X|Tail],Tail).
delt(X,[Y|Tail],[Y|Tail1]):-
delt(X,Tail,Tail1).
