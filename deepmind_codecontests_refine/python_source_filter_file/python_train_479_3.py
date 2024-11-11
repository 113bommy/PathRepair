n = int(input())
sum = 0
res = 0
cnt = dict()
a = list(map(int, input().split()))
for i in range(n):
  sub = 0
  num = 0
  for j in range(-1, 2, 1):
    if (a[i] + j) in cnt:
      sub += (a[i] + j) * cnt[a[i] + j]
      num += cnt[a[i] + j]
  res += (i - num) * a[i] - (sum - sub)
  sum += a[i]
  cnt[a[i]] = cnt.get(a[i], 0)
print(res)