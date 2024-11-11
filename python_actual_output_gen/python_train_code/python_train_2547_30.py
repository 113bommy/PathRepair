n = int(input())
s = 0
for i in range(n):
  l, r = map(int, input().split())
  s += r-l
print(s)