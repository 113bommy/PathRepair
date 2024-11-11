N=int(input())
A=list(map(int,input().split()))
A.sort(reverse=True)
P=A[0]
for i in range(2,N):
  P+=A[(i>>1)<<1]
print(P)
