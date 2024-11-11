w,h,n=map(int,input().split())
lw=0;rw=w;lh=0;rh=h
for _ in range(n):
  x,y,a=map(int,input().split())
  if a==1:
    lw=max(lw,x)
  elif a==2:
    rw=min(rw,x)
  elif a==3:
    lh=max(lh,y)
  else:
    rh=min(rh,y)
print(max((rh-lh)*(rw-lw),0))