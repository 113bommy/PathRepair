N,K,Q=map(int,input().split())
QL=[0]*Q
NL=[K-Q]*N
for i in range(Q):
  L[i]=int(input())
  NL[L[i]]+=1
for i in range(N):
  print('Yes' if NL[i]>0 else 'No')
  