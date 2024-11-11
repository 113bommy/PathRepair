n,k=map(int,input().split())
P=[list(map(int,input().split())) for _ in range(n)]
X=sorted(list(map(lambda x:x[0],P)))
Y=sorted(list(map(lambda x:x[1],P)))
s=(X[0]-X[-1])*(Y[0]-Y[-1])
ans=0
for r in range(n-1,0,-1):
  for l in range(r):
    for u in range(n-1,0,-1):
      for b in range(u):
        c=0
        for p in P:
          if X[l]<=p[0]<=X[r] and Y[b]<=p[1]<=Y[u]:
            c+=1
        if c>=k:
          s=min(s,(X[r]-X[l])*(Y[u]-Y[b]))
        else:break
    if u==n-1 and b==0 and c<k:
      break
print(s)