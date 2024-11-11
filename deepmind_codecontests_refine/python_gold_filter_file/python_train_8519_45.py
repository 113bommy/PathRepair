n=int(input())
a=list(map(int,input().split()))
if max(a)-min(a)>=2:exit(print("No"))
if len(set(a))==1:
  m=a[0]
  if m==n-1 or 2*m<=n:print("Yes")
  else:print("No")
else:
  x=a.count(min(a))
  y=n-x
  if x<max(a) and 2*(max(a)-x)<=y:print("Yes")
  else:print("No")