m = int(input())
d, s = 0, 0
for _ in range(m):
  a, b = map(int, input().split())
  s += a*b
  d += b
print(d-1 + (s-1)//9)
