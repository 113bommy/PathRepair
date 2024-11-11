N,M=map(int,input().split())
L=list(map(int,input().split()))
S=sum(L)
L.sort()
a=L[N-M]
if a*4*M<S:
  print('NO')
else:
  print('Yes')