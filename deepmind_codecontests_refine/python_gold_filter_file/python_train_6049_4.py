R=lambda:map(int,input().split())
n,*a=R()
m=min(a)
c=[*R()]
s=0
for x,y in zip(c[:n//2],c[::-1]):
 if x^y==1:print(-1);exit()
 if x==y:
  if x==2:s+=2*m
 else: s+=a[min(x,y)]
print(s+n%2*(c[n//2]==2)*m)