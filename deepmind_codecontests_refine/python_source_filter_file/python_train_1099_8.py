import sys 
def BigMod(a,p,m):
    if p == 0: return 1
    if (p%2):
        return ((a%m)*(BigMod(a, p-1, m)))
    else:
        c = BigMod(a, p/2, m)
        return ((c%m)*(c%m))%m 
B = 1378
P = int(input())
M = 10
if P == 0:
    print(1)
else:
    print(BigMod(B, P, M))