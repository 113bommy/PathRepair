n, m = map(int, input().split())
a = list(map(int, input().split()))

l = []
for _ in range(m):
    l.append(int(input()))

last = dict()
for i in range(n):
    last[a[i]] = i

dp = [0] * n
dp[0] = len(set(a))
for i in range(n - 1):
    if last[a[i]] == i:  # this is last el.
        dp[i + 1] = dp[i] - 1
    else:
        dp[i + 1] = dp[i]

res = []
for l_i in l:
    res.append(dp[l_i - 1])
print("\n".join(map(str, res)))
