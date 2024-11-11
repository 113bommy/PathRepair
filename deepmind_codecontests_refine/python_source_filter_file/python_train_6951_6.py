import itertools as it
n,m,k=list(map(int,input().split()))
S=[list(str(input())) for h in range(m)]
ans=0
for i in it.product([0,1],repeat=n):
  for j in it.product(range(2),repeat=m):
    count=0
    for h in range(n):
      for c in range(m):
        if S[h][c]=="#" and i[h]+j[c]==0:
          count+=1
    if count==k:
      ans+=1
print(ans)