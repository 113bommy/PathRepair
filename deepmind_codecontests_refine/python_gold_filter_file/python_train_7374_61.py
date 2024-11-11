n = int(input())
x = 0
for _ in range(n):
  s, e = map(int, input().split())
  x += e - s + 1
print(x)