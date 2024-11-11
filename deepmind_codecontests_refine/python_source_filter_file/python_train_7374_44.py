n, a = int(input()), 0
for i in range(n):
  l, r = int(input().split())
  a += r - l + 1
print(a)