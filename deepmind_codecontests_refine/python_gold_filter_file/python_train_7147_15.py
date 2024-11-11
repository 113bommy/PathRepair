from itertools import accumulate


n, k = map(int, input().split())
a = list(map(int, input().split()))
t = list(map(int, input().split()))

ans = sum(a[i] for i in range(n) if t[i])
a = [0 if t[i] else a[i] for i in range(n)]
sms = list(accumulate(a))
sms.append(0)
ans += max(sms[i + k - 1] - sms[i - 1] for i in range(n - k + 1))

print(ans)
