def bs(cnt):
    global n, m, k
    l = 1
    r = min(n, m) + 1
    while (l + 1 != r):
        md = l + (r - l) // 2
        res = n // (md * k)
        if (n % (md * k) >= md):
            res += 1
        if (res >= cnt):
            l = md
        else:
            r = md
    return l


n, k, m, d = map(int, input().split())
ans = 0
for i in range(1, d + 1):
    h = bs(i)
    h1 = n // (h * k)
    if (n % (h * k) != 0):
        h1 += 1
    if (h1 != i):
        continue
    ans = max(ans, h * i)
print(ans)