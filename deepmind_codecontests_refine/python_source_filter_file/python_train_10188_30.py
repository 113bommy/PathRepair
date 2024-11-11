n = int(input())
p = list(map(int,input().split()))
a = []
b = []
x = [0]*n
for i in range(n):
  x[p[i]-1] = 1000000+i
a.append(1)
b.append(x[0]-1)
for i in range(1,n):
  y = a[-1]+1
  z = b[-1]-1
  if y+z>x[i]:
    z = x[i]-y
  if y+z <x[i]:
    y = x[i]-z
  a.append(y)
  b.append(z)
print(*a)
print(*b)