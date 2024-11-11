x,y=map(int,input().split())
if x%y==0 or y==1:print(-1)
else:print(x*(y-1))