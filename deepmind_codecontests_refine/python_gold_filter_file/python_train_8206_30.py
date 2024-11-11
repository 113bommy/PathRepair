n,*a=map(int,open(0).read().split())
x=a[0]
y=sum(a[1:])
ans=abs(x-y)
for i in a[1:-1]:
  x+=i
  y-=i
  ans=min(ans,abs(x-y))
print(ans)
