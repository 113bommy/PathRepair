'''input
20
'''

from collections import defaultdict
import math
from functools import reduce
from heapq import heapify, heappush, heappop


mod = 998244353


def mul_mod(a, b):
    return ((a % mod) * (b % mod)) % mod


def add_mod(a, b):
    return ((a % mod) + (b % mod)) % mod


for _ in range(1):  # (int(input())):
    n = int(input())
    ans = [10]

    for i in range(2, n + 1):
        temp = mul_mod(pow(10, i - 1, mod), 9)
        temp = mul_mod(temp, 2)
        temp2 = pow(10, i - 2, mod)
        temp2 = mul_mod(temp2, 81)
        temp2 = mul_mod(temp2, i - 2)

        ans.append(add_mod(temp2, temp))
    print(*ans[::-1])
