n, m = map(int, input().split())
cnt = 0
while n <= m:
  n *= 2
  cnt += 1
print(n)
