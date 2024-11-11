N=int(input())
A=list(map(int,input().split()))
X=0
for i in range(N-1):
  if A[i+1]>A[i]:
    X+=A[i+1]-A[i]
    A[i+1]=A[i]
print(X)