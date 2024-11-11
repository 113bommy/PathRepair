n, h, k = map(int, input().split())

p = list(map(int, input().split()))
s = 0
cur = 0
shift = 0

for i in range(n):
  if cur + p[i] <= h:
    cur += p[i]
  else:
    s += cur / k
    cur = cur % k
    if cur + p[i] > h:
      s += 1
      cur = 0
    cur += p[i]

s += (cur / k) + (1 if cur % k != 0 else 0)


print(s)