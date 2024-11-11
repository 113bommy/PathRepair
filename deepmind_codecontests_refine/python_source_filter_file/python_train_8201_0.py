import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))

XOR=0
for a in A:
    XOR^=a

for i in range(N):
    A[i] &=~XOR
    
USED=[0]*60

for bi in range(60,-1,-1):
    for i in range(N):
        if USED[i]==0 and A[i] & (1<<bi)!=0:
            USED[i]=1
            useind=i
            break
    else:
        continue

    for i in range(N):
        if i==useind:
            continue
        if A[i] & (1<<bi)!=0:
            A[i]^=A[useind]
            
ANS=0
for a in A:
    ANS^=a

print(2*ANS+XOR)
