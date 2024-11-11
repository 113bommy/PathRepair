w,h,n=map(int,input().split())
x=y=0
for i in range(n):
  xi,yi,a=map(int,input().split())
  if a==1:
    x=max(x,xi)
  elif a==2:
    w=min(w,xi)
  elif a==3:
    y=max(y,yi)
  elif a==4:
    h=min(h,yi)    
print(0 if x>=w or y>=h else (w-x)*(h-y))
