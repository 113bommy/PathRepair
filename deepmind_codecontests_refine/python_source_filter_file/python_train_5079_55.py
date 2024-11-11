from bisect import bisect_right
n,d,a=map(int,input().split())
xh=[list(map(int,input().split()))for _ in range(n)]
xh.sort()
x=[]
h=[]
for xx,hh in xh:
  x.append(xx)
  h.append(hh)

not_imos=[0]*(n+1)
atk_n=0
ans=0
for i in range(n):
  atk_n-=imos[i]
  h[i]-=atk_n*a
  if h[i]<0:h[i]=0
  atk_i=0--h[i]//a
  ans+=atk_i
  atk_n+=atk_i
  imos[bisect_right(x,x[i]+d*2)]+=atk_i
print(ans)