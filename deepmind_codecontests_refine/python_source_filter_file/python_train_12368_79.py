w,h,x,y=map(int,input().split())
ans=1
if w/2==x or h/2==y:
  ans=0
print(w*h/2,ans)