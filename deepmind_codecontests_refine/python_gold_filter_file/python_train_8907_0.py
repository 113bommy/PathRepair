a, b = map(int, input().split())
import math
g = math.gcd(a, b)
lis = [i for i in range(1, int(math.sqrt(g)) + 1) if g%i == 0]
for i in lis[::-1]: lis.append(g//i)
n = int(input())
for _ in range(n):
    a, b = map(int , input().split())
    import bisect
    x = bisect.bisect(lis, b) - 1
    if lis[x] < a: print(-1)
    else: print(lis[x])
        