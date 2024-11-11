import math

__author__ = 'aste'


def z_function(s):
    n = len(s)
    i = 1
    l = 0
    r = 0
    z = [0]*n
    while i < n:
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while (i + z[i] < n) and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
        i += 1
    return z


def divisors(n):
    res = []
    sqrt = int(math.sqrt(n))
    for i in range(1, sqrt + 1):
        if n % i == 0:
            res.append(i)
            if i != n//i:
                res.append(n//i)
    return res


def string_divisors(s):
    n = len(s)
    res = set()
    div = divisors(n)
    z = z_function(s)
    for d in div:
        ok = True
        for i in range(d, n, d):
            if z[i] < d:
                ok = False
                break
        if ok:
            res.add(s[0:d])
    res.add(s)
    return res


def main():
    s1 = input()
    s2 = input()
    s1_divs = string_divisors(s1)
    s2_divs = string_divisors(s2)
    print(len(s1_divs.intersection(s2_divs)))

main()