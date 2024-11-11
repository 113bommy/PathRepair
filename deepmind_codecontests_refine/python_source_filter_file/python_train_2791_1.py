N,K=map(int,input().split())
H=list(map(int,input().split()))
DP=[0]*(N+1)
for i in range(2,N+1):
  L=[DP[i-j-1]+abs(H[i-1]-H[i-j-2])for j in range(min(K,i-1))]
  DP[i]=min(L)
print(DP[-1])