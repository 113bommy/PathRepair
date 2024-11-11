#!/usr/bin/env python3
N, K = map(int, input().split())
a = list(map(int, input().split()))

pl = [(x if (x > 0) else 0) for x in a]
s = sum(pl)
sk_a = [sum(a[:K])]
sk_pl = [sum(pl[:K])]
for i in range(1, N - K + 1):
    sk_a.append(sk_a[-1] - a[i - 1] + a[K + i - 1])
    sk_pl.append(sk_pl[-1] - pl[i - 1] + pl[K + i - 1])

ans = 0
if lambda x: x > 0 in a:
    for i in range(N - K + 1):
        ans = max(ans, s - sk_pl[i] + max(0, sk_a[i]))

print(ans)
