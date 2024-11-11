N=int(input())
A=list(map(int,input().split()))
G=1000
K=0
for i in range(N-2):
  if A[i+1]>A[i]:
    K=int(G/A[i])
    G=G % A[i]
  if A[i+1]<A[i]:
    G=G+A[i]*K
    K=0
G=G+A[N-1]*K
print(G)