N=int(input())
A=list(map(int,input().split()))
X=[0]*N
for i in range(N):
   X[A[i]-1]=i+1

print(*X)