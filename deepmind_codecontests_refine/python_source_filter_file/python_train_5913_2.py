N,K=map(int,input().split())
A=list(map(int,input().split()))
DP=dict()
if K==1:
  print(0)
  exit()
DP[0]=1
P=0
Y=[0]*(N+1)
for i in range(N):
  Y[i+1]=(Y[i]+A[i]-1)%K
  P+=DP.get(Y[i+1],0)
  DP[Y[i+1]]=DP.get(Y[i+1],0)+1
  if i>=K-2:
    DP[Y[i-K+2]]-=1