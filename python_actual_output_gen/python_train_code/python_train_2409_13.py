w,h,n=map(int,input().split())
x_b=w
x_s=0
y_b=h
y_s=0
for i in range(n):
  x,y,a=map(int,input().split())
  if a==1:
    x_b=min(x,x_b)
  elif a==2:
    x_s=max(x,x_s)
  elif a==3:
    y_b=min(y,y_b)
  else:
    y_s=max(y,y_s)

if x_b<=x_s or y_b<=y_s:
  print(0)
else:  
  print((x_b-x_s)*(y_b-y_s))