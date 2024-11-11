import bisect

n, k = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n - 1):
  a[i] -= 1
  a[i + 1] += a[i]
a[n - 1] -= 1

memo = {0 : []}
for i in range(n):
  if a[i] % k not in memo.keys():
    memo[a[i] % k] = [i]
  else:
    memo[a[i] % k].append(i)

ans = bisect.bisect_left(memo[0], k - 1)

for i in memo.keys():
  for j in range(len(memo[i]) - 1):
    ans += bisect.bisect_left(memo[i], memo[i][j] + k) - 1 - j

print(ans)