n,x,m=map(int,input().split())
a=[x]
su=x
s={x}
for i in range(n):
  x=(x**2)%m
  if x in s:
    n-=i+1
    a=a[a.index(x):]
    l=len(a)
    su+=sum(a)*(n//l)
    n-=(n//l)*l
    su+=sum(a[:n])
    print(su)
    exit()
  a.append(x)
  su+=x
  s.add(x)
print(su)