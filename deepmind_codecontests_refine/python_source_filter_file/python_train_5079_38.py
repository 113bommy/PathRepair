from bisect import bisect_left,bisect_right
n,d,a=map(int,input().split())
xh=[list(map(int,input().split()))for _ in range(n)]
xh.sort()
x=[]
h=[]
for xx,hh in xh:
  x.append(xx)
  h.append(hh)
imos=[0]*(n+1)
mi=0
ans=0
for i in range(n):
  mi-=imos[i]
  h[i]=max(h[i]-mi,0)
  atk=0--h[i]//a
  ans+=atk
  mi+=atk
  point=x[i]+d*2
  index=bisect_right(x,point)
  imos[index]+=atk
print(ans)