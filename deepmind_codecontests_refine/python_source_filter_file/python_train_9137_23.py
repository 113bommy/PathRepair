n, p = map(int, input().split())
s = list(input())

ans = 0
if p == 2 or p == 5:
    for i in range(n):
        if int(s[i]) % p == 0:
            ans += i + 1
else:
    d = [0] * (n + 1)
    ten = 1
    for i in range(n - 1, -1, -1):
        a = int(s[i]) * 10 ** ten % p
        ten *= 10
        ten %= p
        d[i - 1] = (d[i] + a) % p
    cnt = [0] * p
    for i in range(n, -1, -1):
        ans += cnt[d[i]]
        cnt[d[i]] += 1

print(ans)
