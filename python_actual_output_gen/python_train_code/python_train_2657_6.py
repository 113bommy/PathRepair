n, s = [int(i) for i in input().strip().split()]
ans = -1
for i in range(n):
  d, c = [int(i) for i in input().strip().split()]
  if d < s:
    ans = max(ans, (100 - c)%100)
  elif d == s and c == 0:
    ans = max(ans, 0)
print(s)    