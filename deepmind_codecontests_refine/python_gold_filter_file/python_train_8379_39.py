mod = int(10**9 + 7)
def power(a, n):
    res = 1
    while n > 0:
        if n%2 == 0:
            a = (a * a) % mod
            n //= 2
        else:
            n -= 1;
            res = (a * res) % mod
    return res
a = int(input())
print((power(3, (a*3)) - power(7, a)) % mod)