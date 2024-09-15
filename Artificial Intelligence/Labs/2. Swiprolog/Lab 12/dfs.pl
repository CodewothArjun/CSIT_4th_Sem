% Graph representation
s(a, b).
s(a, c).
s(b, d).
s(b, e).
s(c, f).
s(c, g).
s(d, h).
s(e, i).
s(e, j).
s(f, k).
% Goal nodes
goal(f).
goal(j).
% Check if an element is a member of a list
member(X, [X|_]).
member(X, [_|Tail]) :- member(X, Tail).
% Solve using depth-first search
solve(Node, Solution) :-
    depthfirst([], Node, Solution).
% If the current node is a goal, return the solution
depthfirst(Path, Node, [Node|Path]) :-
    goal(Node).
% Explore the next node if the current one is not a goal
depthfirst(Path, Node, Solution) :-
    s(Node, Node1),
    not(member(Node1, Path)),
    depthfirst([Node|Path], Node1, Solution).
