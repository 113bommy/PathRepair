n = int(input())
from bisect import bisect_left as br 
a = [int(x) for x in input().split()]
mn = [10 ** 10 for i in range(n)]
mn[-1] = a[-1]
for i in range(n - 2, -1 , -1):
    mn[i] = min(mn[i + 1], a[i])
ans = [0] * n
for i in range(n):
    pos = br(mn, a[i])
    #print(pos)
    if a[pos - 1] < a[i]:
        ans[i] = max(-1, pos - 1- i - 1)
    else:
        ans[i] = -1
print(*ans)
