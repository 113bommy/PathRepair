N,K=map(int,input().split())
X=list(map(int,input().split()))
if N==1:
  print(0);exit()

ans=float("Inf")
for i in range(N-K):
  ans=min(ans, X[i+K-1]-X[i]+ min(abs(X[i+K-1]),abs(X[i]))  )

print(ans)
  