located_in(nccs,kathmandu).
located_in(thamel,kathmandu).
located_in(dharahara,kathmandu).
located_in(pokhara,kaski).
located_in(X,nepal):- located_in(X,kathmandu).
located_in(X,nepal):- located_in(X,lalitpur).
located_in(X,western_region):- located_in(X,kaski).
located_in(X,asia):- located_in(X,nepal).
located_in(X,asia):- located_in(X,western_region).