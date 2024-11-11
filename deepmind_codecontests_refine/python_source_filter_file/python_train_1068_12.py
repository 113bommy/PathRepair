from math import *

for t in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    diff = 1
    c = a[0]
    for i in a:
        if i == c:
            pass
        else:
            diff += 1
            c = i
    ans = 1
    diff -= k
    k -= 1
    if k == 0 and diff != 0:
        print(-1)
    else:
        if k != 0:
            ans += ceil(diff / k)
        print(ans)
