n = int(input())
a, b, c = 0, 0, 0

for i in range(n):
  x, y, z = map(int, input().split())
  a, b, c = a+max(y,z), b+max(x,z), c+max(x,y)
print(max(a,b,c))