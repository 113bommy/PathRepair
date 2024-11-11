from math import gcd
n = int(input())
a = map(int, input().split())
mn, res = min(a), []
for i in a:
    if gcd(mn, i) == mn:
        res.append(mn)
        res.append(i)
    else:
        print(-1)
        exit()
print(len(res))
print(*res)
