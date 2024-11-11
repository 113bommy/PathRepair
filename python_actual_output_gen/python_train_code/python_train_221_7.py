n,m=map(int,input().split())
*x,=map(int,input().split())
*y,=map(int,input().split())
mod=10**9+7
vx,vy=0,0
for i in range(n):
  vx+=(i*x[i]-(n-i-1)*x[i])
for j in range(m):
  vy+=(j*x[j]-(m-j-1)*x[j])
print(vx*vy%mod)