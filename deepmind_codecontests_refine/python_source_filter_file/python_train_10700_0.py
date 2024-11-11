N,K=map(int,input().split())
p=list(map(int,input().split()))
S=sum(p[:K])
T=0
for i in range(N-K):
  S=S-p[i]+p[i+K]
  T=max(T,S)
print((T+K)/2)