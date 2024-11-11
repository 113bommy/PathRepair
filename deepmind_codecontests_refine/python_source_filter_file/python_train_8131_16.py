import sys
input = sys.stdin.readline

n,k=map(int,input().split())
A=list(map(int,input().split()))
A.append(0)

A=list(set(A))

A.sort()

ANS=[]
for i in range(1,len(A)):
    ANS.append(A[i]-A[i-1])

ANS+=[0]*(k-len(ANS))
for a in ANS:
    print(a)
