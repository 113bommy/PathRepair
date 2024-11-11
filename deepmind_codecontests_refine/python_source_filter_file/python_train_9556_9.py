N,X,D=map(int,input().split())

from collections import defaultdict

A=defaultdict(list)

A[0].append([0,0])

MIN=0
MAX=0

if D==0:
    w=1
else:
    w=D

for i in range(N):
    MIN+=X+D*i
    MAX+=X+D*(N-1-i)

    A[MIN%w].append(sorted([MIN,MAX]))

D=abs(D)
if D==0:
    if X==0:
        D=1
    else:
        D=X
ANS=0

for mod in A:
    B=A[mod]
    B.sort()
    C=[]

    for MIN,MAX in B:
        
        if C==[]:
            C.append((MIN,MAX))
        x,y=C[-1]

        if y>=MIN:
            C[-1]=(x,MAX)
        else:
            C.append((MIN,MAX))

    for MIN,MAX in C:
        ANS+=(MAX-MIN)//D+1
    
print(ANS)
