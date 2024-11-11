from sys import stdin, stdout
from math import ceil

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

t = int(input())
for _ in range(t):
    a, b, q = map(int, stdin.readline().split())

    if max(a, b)%min(a, b) == 0:
        for _ in range(q):
            l, r = map(int, stdin.readline().split())
            print(0)

    else:
        lcm = (a*b)//gcd(a, b)
        m = max(a, b)
        how = lcm - m
        ans = []
        for _ in range(q):
            l, r = map(int, stdin.readline().split())

            # From solution page. if b>=a, the statement is NOT satisfied for every LCM-b quantities. We have to find out how many LCM-b quantities exist in [l, r]. Find the quantity in [0, l-1]. Find it in [0, r]. Subtract the two to get [l, r]
            
            # for [0, l-1]
            x1 = ((l-1)//lcm)*how
            final1 = (l-1)%lcm
            x1 += max(0, final1 - b + 1)

            # repeat above steps for [0, r]
            x2 = ((r)//lcm)*how
            final2 = (r)%lcm
            x2 += max(0, final2 - b + 1)

            ans.append(x2-x1)
        print(*ans)