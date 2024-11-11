w,h,n=map(int,input().split())
x1=0
x2=w
y1=0
y2=h
for i in range(n):
  x,y,a=map(int,input().split())
  if a==1:
    x1=max(x1,x)
  if a==2:
    x2=min(x2,x)
  if a==3:
    y1=max(y1,y)
  if a==4:
    y2=min(y2,y)
if x2<x1 or y1<y2:
  print(0)
else:
  print((x2-x1)*(y2-y1))
