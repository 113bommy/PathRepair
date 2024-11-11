N,Q=map(int,input().split())
S=[i for i in input()]
t=[0]*(N+1)
for i in range(N-1):
  t[i+1]=t[i]+(1 if S[i]=='A' and S[i+1]=='C' else 0)
for i in range(Q):
  l,r=map(int, input().split())
  print(t[r-1]-t[l-1])