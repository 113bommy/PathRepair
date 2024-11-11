import math


def check(n):
    lg = int(math.ceil(math.log2(n)))
    v = math.pow(2, lg) - 1
    return n == v


for q in range(int(input())):
    a = int(input())
    if check(a):
        ans = 1
        sp = 1000000000000
        i = 2
        while i * i <= a:
            while a % i == 0:
                sp = min(sp, i)
                ans *= sp
                a //= i
            i += 1
        if a > 1:
            sp = min(sp, a)
            ans *= a
        ans //= sp
        print(ans)
    else:
        lg = len(bin(a)[2:])
        print(int(pow(2, lg)) - 1)

