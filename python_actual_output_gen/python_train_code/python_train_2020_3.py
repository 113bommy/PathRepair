n = int(input())
for i in range(n):
    ans = 0
    t = [int(k) for k in input().split()]
    if t[2]<=t[0] and t[2]<=t[1]:
        t[0] -= t[2]
        t[1] -= t[2]
        ans += t[2]
        m, n = (t[0], t[1]) if t[0] <= t[1] else (t[1], t[0])
        if 2 * m > n:
            ans += n // 2 + 1
        else:
            ans += m
        print(ans)
    else:
        print(t[0] if t[0] <= t[1] else t[1])
