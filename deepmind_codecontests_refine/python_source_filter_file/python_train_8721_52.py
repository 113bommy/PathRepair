N,M=map(int,input().split())
A=list(map(int,input().split()))

A.sort(reverse=True)
if A[M-1] > sum(A)/(4*M):
  print('Yes')
else:
  print('No')