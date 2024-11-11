a,b,c,x,y=map(int,input().split())
c=min(c*2,a+b)
ans=min(x,y)*c
if x>y:ans+=min(a,c)*(y-x)
else:ans+=min(b,c)*(x-y)
print(ans)