n=int(input())
a=list(map(int,input().split()))
a.sort()
xy=[]
for i in range(n-2,0,-1):
  y=a[i]
  if y>0:
    x=a[0]
    a[0]-=y
  else:
    x=a[n-1]
    a[n-1]-=y
  xy.append((x,y))
print(a[n-1]-a[0])
xy.append((a[n-1],a[0]))
print('\n'.join([' '.join(map(str,t)) for t in xy]))