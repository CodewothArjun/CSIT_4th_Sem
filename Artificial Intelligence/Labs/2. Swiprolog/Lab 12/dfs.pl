go(Start, Goal) :-
	empty_stack(Empty_been_list),
	stack(Start, Empty_been_list, Been_list),
	path(Start, Goal, Been_list).
	
	% path implements a depth first search in PROLOG
	
	% Current state = goal, print out been list
path(Goal, Goal, Been_list) :-
	reverse_print_stack(Been_list).
	
path(State, Goal, Been_list) :-
	mov(State, Next),
	% not(unsafe(Next)),
	not(member_stack(Next, Been_list)),
	stack(Next, Been_list, New_been_list),
	path(Next, Goal, New_been_list), !.
	
reverse_print_stack(S) :-
	empty_stack(S).
reverse_print_stack(S) :-
	stack(E, Rest, S),
	reverse_print_stack(Rest),
	write(E), nl.
  
