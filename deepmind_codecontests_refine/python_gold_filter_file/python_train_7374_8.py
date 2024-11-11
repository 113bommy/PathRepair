n = int(input())
s = 0
for _ in range(n):
  a, b = map(int, input().split())
  s += (b - a + 1)
print(s)