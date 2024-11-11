import sys
input = sys.stdin.readline

n,m=map(int,input().split())
W=[0]+list(map(int,input().split()))
E=[tuple(map(int,input().split())) for i in range(m)]
S=int(input())

ELIST=[[] for i in range(n+1)]
EW=[0]*(n+1)

for x,y in E:
    ELIST[x].append(y)
    ELIST[y].append(x)

    EW[x]+=1
    EW[y]+=1


from collections import deque
Q=deque()
USED=[0]*(n+1)

for i in range(1,n+1):
    if EW[i]==1:
        USED[i]=1
        Q.append(i)

EW[S]+=1<<50
USED[S]=1

while Q:
    x=Q.pop()
    EW[x]-=1

    for to in ELIST[x]:
        if USED[to]==1:
            continue
        EW[to]-=1

        if EW[to]==1 and USED[to]==0:
            Q.append(to)
            USED[to]=1

#print(EW)
LOOP=[]

ANS=0
for i in range(1,n+1):
    if EW[i]!=0:
        ANS+=W[i]
        LOOP.append(i)

SCORE=[0]*(n+1)
USED=[0]*(n+1)

for l in LOOP:
    SCORE[l]=ANS
    USED[l]=1

Q=deque(LOOP)

while Q:
    x=Q.pop()

    for to in ELIST[x]:
        if USED[to]==1:
            continue

        SCORE[to]=W[to]+SCORE[x]
        Q.append(to)
        USED[to]=1

print(max(SCORE))
