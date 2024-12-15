boy('Sanjay').
boy('Ram').
boy('Aakash').
boy('Kshitiz').
boy('Ruman').
boy('Binod').
girl('Geeta').
girl('Ruza').
male('Asha Kaji').
male('Sanjay').
female('Chaitya Maya').
female('Anita').
father('Asha Kaji','Anita').
father('Asha Kaji','Sanjay').
father('Purna','Asha Kaji').
mother('Chaitya Maya','Anita').
mother('Chaitya Maya','Sanjay').
husband('Asha Kaji','Chitya Maya').
sister('Anita','Sanjay').
brother('Sanjay','Anita').
grandfather('Purna','Sanjay').
grandfather('Purna','Anita').
grandson('Sanjay','Purna').
granddaughter('Anita','Purna').
sum:-
write('Enter first number : '),read(X),
write('Enter second number : '),read(Y),
Z is X+Y,
write('Sum is '),write(Z).