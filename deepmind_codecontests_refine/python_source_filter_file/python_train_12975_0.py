n,r=map(int,input().split())
y=[]
x=list(map(int,input().split()))
for xi in x:
  yi=r
  for tx,ty in zip(x,y):
    if xi-r<=tx<=xi+r:
      dy=(4.0*r**2-(tx-xi)**2)**0.5
      yi=max(yi,ty+dy)
  y.append(yi)
print(*y)
