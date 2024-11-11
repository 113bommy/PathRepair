# https://codeforces.com/problemset/problem/1042/B
nb_juices = int(input())
cABC = 100001
cAB = 100001
cAC = 100001
cBC = 100001
cA = 100001
cB = 100001
cC = 100001
for n in range(nb_juices):
    c, s = [x for x in input().split()]
    c = int(c)
    vA = s.count("A")
    vB = s.count("B")
    vC = s.count("C")
    if vA==1 and vB==1 and vC==1:
        if c<cABC:
            cABC=c
    if vA==1 and vB==1:
        if c<cAB:
            cAB=c
    if vA==1 and vC==1:
        if c<cAC:
            cAC=c
    if vB==1 and vC==1:
        if c<cBC:
            cBC=c
    if vA==1:
        if c<cA:
            cA=c
    if vB==1:
        if c<cB:
            cB=c
    if vC==1:
        if c<cC:
            cC=c
cout = min(cABC, cAB+cC, cAC+cB, cBC+cA, cA+cB+cC)
if cout == 100001:
    print(-1)
else:
    print(cout)
