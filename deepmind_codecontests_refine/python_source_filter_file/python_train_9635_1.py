n,x=[int(i) for i in input().strip().split()]
a=[int(i) for i in input().strip().split() if int(i)!=x]
if len(a)<=1:
  ans=0
else:
  a=sorted([x]+a)
  ind=a.index(x)
  if ind==0:
    ans=a[-2]-a[0]
  elif ind==len(a):
    ans=a[-1]-a[1]
  else:
    ans=min((a[ind]+a[-2]-2*a[0]), (2*a[-2]-a[ind]-a[0]), (a[ind]+a[-1]-2*a[1]), (2*a[-1]-a[ind]-a[1]))
print(ans)