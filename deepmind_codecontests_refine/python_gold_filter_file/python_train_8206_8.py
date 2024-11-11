n=int(input())
*l, = map(int,input().split())
x = 0
y = sum(l)
xy = [10**15]*n
for i in range(n-1):
  x+=l[i]
  y-=l[i]
  xy[i] = abs(x-y)
print(min(xy))