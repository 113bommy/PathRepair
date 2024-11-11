import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))

from itertools import accumulate
SUM=list(accumulate(A))
SUM.append(0)

BLIST=[[0]*n for i in range(n)]
B2=[]

for i in range(n):
    for j in range(i,n):
        BLIST[i][j]=SUM[j]-SUM[i-1]
        B2.append(SUM[j]-SUM[i-1])

B2=set(B2)
ANS=[]
ANSLEN=0

for bsum in B2:
    i=0
    j=0
    CANDI=[]
    USED=-1

    for i in range(n):
        for j in range(USED+1,i+1):
            if BLIST[j][i]==bsum:
                CANDI.append([j+1,i+1])
                USED=i
                break

    if len(CANDI)>ANSLEN:
        ANS=CANDI
        ANSLEN=len(CANDI)

print(len(ANS))
for ans in ANS:
    print(*ans)
        
        
