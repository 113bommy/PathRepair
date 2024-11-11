def gcd(a,b):
    # a作为除数 必须大于b
    a, b = (a, b) if a >=b else (b, a)
    while b:
        a,b = b,a%b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

import math
a, b = [int(i) for i in input().split(' ')]
if a % b == 0 or b % a == 0:
    print(0)
else:
    n = abs(a-b)
    ks = []
    for i in range(1, min(n, int(math.sqrt(10**9))+1)+1):
        if n % i == 0:
            if a % i == 0:
                ks.append(0)
            else:
                ks.append(i - a%i)
            ks.append(n//i - a%(n//i))
    ks = sorted(set(ks))
    print(ks)
    k = ks[0]
    # print(ks)
    minn = lcm(a+k, b+k)

    for i in ks[1:]:
        if lcm(a+i, b+i) < minn:
            k = i
            minn = lcm(a+i, b+i)
    print(k)