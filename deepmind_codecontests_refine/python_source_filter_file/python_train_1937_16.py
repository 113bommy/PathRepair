import math
def bin_coeff(p, n):
    ret_val = 1
    for i in range(p):
        ret_val *= n - i
        ret_val //= i + 1
    
    return ret_val

n = int(input())

a = [int(x) for x in input().split()]

b = sorted(a)

from itertools import groupby
c = [len(list(group)) for key, group in groupby(b)]
print(c)

sum = 3
i = 0
while sum - c[i] > 0:
    sum -= c[i]
    i += 1

ans = bin_coeff(sum, c[i])
print(ans)
