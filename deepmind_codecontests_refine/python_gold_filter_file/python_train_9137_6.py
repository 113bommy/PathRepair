n, p = map(int, input().split())
s = input()

ans = 0
if p in (2, 5):
    for i, j in enumerate(s):
        if int(j) % p == 0:
            ans += i + 1

else:
    cnt = [0] * p
    cnt[0] = 1
    now = 0
    for i, j in enumerate(reversed(s)):
        now = (int(j) * pow(10, i, p) + now) % p
        ans += cnt[now]
        cnt[now] += 1

print(ans)