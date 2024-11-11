from math import gcd


def solve(r, b, k):
    g = gcd(r, b)
    r //= g
    b //= g
    if r > b:
        r, b = b, r
    if (k - 1) * r + 1 < b:
        return "REBEL"
    return "OBEY"


for _ in range(int(input())):
    R, B, K = [int(i) for i in input().split()]
    print(solve(R, B, K))
