N=input()
for i in range(8):
    S = ([["+","-"][(i>>j)&1] for j in range(3)])
    seq=N[0]+S[0]+N[1]+S[1]+N[2]+S[2]+N[3]
    if eval(seq)==7:
        print(seq+"=7")
        break