n=int(input())
a=[int(input()) for _ in range(n)]
a.sort()
if n==2:
  x=a[1]-a[0]
elif n%2==0:
  x=(sum(a[n//2+1:])-sum(a[:n//2-1]))*2
  x-=a[n//2-1]
  x+=a[n//2]
elif n==3:
  x=a[2]*2-a[0]-a[1]
  y=a[2]+a[1]-a[0]*2
  x=max(x,y)
else:
  x=(sum(a[n//2+2:])-sum(a[:n//2]))*2
  x+=a[n//2]+a[n//2+1]
  y=(sum(a[n//2+1:])-sum(a[:n//2-1]))*2
  y-=a[n//2]-a[n//2-1]
  x=max(x,y)
print(x)