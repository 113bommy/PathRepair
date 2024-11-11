def mp():
    return map(int, input().split())

n, m = mp()
a = list(mp())

s = [0] * (n + 1)
for i in range(n):
    s[i] = s[i - 1] + a[i]

cnt = [0] * 101
for i in range(n):
    ans = 0
    t = s[i]
    while t > m:
        for j in range(100, 0, -1):
            if cnt[j] != 0:
                k = (t - m + j - 1) // j
                ans += min(k, cnt[j])
                t -= min(k, cnt[j]) * j
    cnt[a[i]] += 1
    print(ans, end = ' ')