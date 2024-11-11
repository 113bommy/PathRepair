import math


def primeFactors(n):
    res = []
    while n % 2 == 0:
        res.append(2),
        n = n // 2

    for i in range(3, int(math.sqrt(n)), 2):

        while n % i == 0:
            res.append(i),
            n = n // i

    if n >= 2:
        res.append(n)

    return res


# Driver Program to test above function

def solve(l1, l2, k, a, b):
    p = len(l1)
    q = len(l2)
    if (p + q) < k:
        return "NO"
    if k == 1:
        if a == b:
            return "NO"
        if b % a == 0:
            return "YES"
        return "N0"
    return "YES"


for _ in range(int(input())):
    a, b, k = map(int, input().split())
    a, b = sorted([a, b])
    l1 = primeFactors(a)
    #print(l1)
    l2 = primeFactors(b)
    #print(l2)
    print(solve(l1, l2, k, a, b))