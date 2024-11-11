import sys
N=int(input())
A=[int(i) for i in input().split()]
if sum(A)%((N*(N+1))//2)!=0:
    print('NO')
    sys.exit()
k=sum(A)//((N*(N+1))//2)
B=[0]*N
for i in range(N):
    B[i]=A[i]-A[i-1]
for a in B:
    if a-k<=0 and (k-a)%N==0:
        continue
    print('NO')
    sys.exit()
print('YES')