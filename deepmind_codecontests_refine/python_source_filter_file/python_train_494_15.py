import math

n = int(input())
mod = 10**9+7
d = {}

zero = 0
for i in range(n):
    a,b = map(int,input().split())
    if a == 0 and b == 0:
        zero += 1
    else:
        g = math.gcd(a,b)
        a //= g
        b //= g
        if b < 0:
            a = -a
            b = -b
        if b == 0 and a == -1:
            a = 1
        if a > 0:
            if (a,b) in d:
                d[(a,b)][0] += 1
            else:
                d[(a,b)] = [1,0]
        else:
            if (b,-a) in d:
                d[(b,-a)][1] += 1
            else:
                d[(b,-a)] = [0,1]
ans = 1
for (a,b),(c,d) in d.items():
    count = (pow(2,c,mod)+pow(2,d,mod)-1)%mod
    ans *= count
    ans %= mod


print(ans+zero-1)


