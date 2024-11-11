n,k=map(int,input().split())
X=list(map(int,input().split()))
ans=[]
for i in range(n-k+1):
  ans.append(X[i+k-1]-X[i]+min(abs(X[i+k-1]),abs(X[i])))
print(min(ans))