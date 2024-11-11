n, m = map(int, input().split())
k = 2 * (m - 1)
for i in range(n):
    s, f, t = map(int, input().split())
    d = t % k
    if s < f: print(k * (s <= d) + f - 1 + t - d)
    elif f < s: print(k * (d + s > k + 1) + k + 1 - f + t - d)
    else: print(t)