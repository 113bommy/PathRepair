n = int(input())
pre = 0
now = 9
ans = 0
t = 0
while now < 1000000000:
    t = t + 1
    if min(n, now) < pre:
        break
    ans += (min(n, now) - pre) * t
    pre = now
    now = now * 10 + 9
print(ans)