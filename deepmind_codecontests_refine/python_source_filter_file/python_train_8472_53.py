from math import ceil

n, k = [int(x) for x in input().split()]
z    = ceil(n / 2)

if k < z:
    print(2 * k - 1)
else:
    print(2 * (k - z))
