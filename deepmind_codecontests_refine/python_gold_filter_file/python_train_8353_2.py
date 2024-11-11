import math
import collections

t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    s = input()
    ctr = collections.Counter(s)

    ans = 0
    for i in range(1,n+1):
        g = math.gcd(i, k)
        l = i // g
        cnt = sum([(v//l)*l for v in ctr.values()])
        if cnt >= i:
            ans = i
    print(ans)
