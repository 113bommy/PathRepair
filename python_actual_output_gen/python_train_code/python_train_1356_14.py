N,K=int(input()),int(input())
res=1
for _ in range(K):
  res=min(res*2,res+K)
print(res)