import collections
N=int(input())
A=list(map(int,input().split()))
s=sum(A)
Q=int(input())
d=collections.Counter(A)
for i in range(Q):
  B,C=map(int,input().split())
  s += d[B]*C - d[B]*B
  print(s)
  if d[C] in d:
    d[C]+=d[B]
  else:
    d[C]=d[B]
  d[B]=0