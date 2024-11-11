def median(a):
  return a[(len(a) + 1) // 2 - 1]
n, x = map(int, input().split())
a, ans = list(map(int, input().split())), 0
if not x in a:
  a = sorted(a + [x])
  ans += 1
while median(a) != x:
  a = sorted(a + [x])
  ans += 1
print(ans)