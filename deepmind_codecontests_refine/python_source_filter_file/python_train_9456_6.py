import itertools
S=input()
TT=itertools.product(["+","-"],repeat=3)
for T in TT:
    A=S[0]+T[0]+S[1]+T[1]+S[2]+T[2]+S[3]
    if eval(A)==7:
        print(A)
        exit()
