# list(map(int, input().split()))
from math import sqrt
n = int(input())
ans = -1e9
z = list(map(int, input().split()))
for t in z:
    if (t < 0):
        ans = max(t, ans)
    else:
        p = sqrt(t)
        while (p + 1) * (p + 1) <= t:
            p += 1
        while p * p > t:
            p -= 1
        if p * p != t:
            ans = max(ans, t)
print(ans)

