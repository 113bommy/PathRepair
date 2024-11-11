N=int(input())
A=[int(i) for i in input().split()]
M=max(A)
S=10**9
j=0
for i in range(N):
  if S>=abs(2*A[i]-M):
    j=i
    S=abs(2*A[j]-M)
print(M,A[j])
