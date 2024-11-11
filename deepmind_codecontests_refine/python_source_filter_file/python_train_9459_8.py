n = int(input())
a = [int(input()) for i in range(n)]
b = sorted(a[::2])
a.sort()
now = 0
ans = 0
br = len(b)
for k,v in enumerate(a):
  if b[now] == v:
    if k % 2:
      ans += 1
      now += 1
  if now == br:
    break
print(ans)