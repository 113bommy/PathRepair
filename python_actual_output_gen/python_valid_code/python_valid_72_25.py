w,h,x,y=map(int,input().split())
huku=0
if w/x==2 and h/y==2:
  huku=1
print(w*h/2,huku)