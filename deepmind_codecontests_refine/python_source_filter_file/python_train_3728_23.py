X,Y,Z,K = map(int, input().split())

A = sorted(list(map(int, input().split())))[:K]
B = sorted(list(map(int, input().split())))[:K]
C = sorted(list(map(int, input().split())))[:K]

ab = sorted(list(a+b for a in A for b in B), reverse = True)[:K]
abc = sorted(list(ab+c for ab in ab for c in C), reverse = True)[:K]

for i in abc : 
    print(i)