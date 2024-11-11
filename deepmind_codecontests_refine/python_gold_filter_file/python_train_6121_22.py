N=int(input())
A=list(map(int,input().split()))
C=[0]*N
for i in range(N):
  C[A[i]-1]=i+1
print(*C)

