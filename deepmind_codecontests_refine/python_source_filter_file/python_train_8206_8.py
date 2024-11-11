n=int(input())
*l, = map(int,input().split())
x = 0
y = sum(l)
xy = [abs(y)]*n
for i in range(n-1):
  x+=l[i]
  y-=l[i]
  xy[i] = abs(x-y)
print(min(xy))