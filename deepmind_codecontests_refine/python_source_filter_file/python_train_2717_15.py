from collections import defaultdict
n = int(input())

a = list(map(int, input().split()))
a.sort(reverse=True)

ans = 0
Max = max(a)
Min = min(a)
ans = 0
if n == 1:
    print(a[0])
    exit()
for i in range(n):
    if a[i] > 0:
        ans += a[i]
    else:
        ans -= a[i]


if Min > 0:
    ans -= Min * 2
    print(ans)
    exit()
else:
    if Max < 0:
        ans += a[i] * 2
        print(ans)
    else:
        print(ans)

