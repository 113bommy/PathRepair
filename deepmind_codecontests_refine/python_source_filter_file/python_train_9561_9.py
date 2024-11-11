n,m=map(int,input().split())
x=[0]*n
y=[0]*n
for i in range(n):
  x[i],y[i]=map(int,input().split())
ans=10**19
for i in range(n):
  for j in range(i+1,n):
    for k in range(j+1,n):
      for l in range(k+1,n):
        xl=min(x[i],x[j],x[k],x[l])
        xr=max(x[i],x[j],x[k],x[l])
        yl=min(y[i],y[j],y[k],y[l])
        yh=max(y[i],y[j],y[k],y[l])
        cnt=0
        for c in range(n):
          cnt+=xl<=x[c]<=xr and yl<=y[c]<=yh
        if cnt>=m:ans=min(ans,(xr-xl)*(yh-yl))
print(ans)