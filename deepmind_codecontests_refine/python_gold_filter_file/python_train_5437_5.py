'''
@Date         : 2020-04-07 14:37:45
@Author       : ssyze
@Description  : 
'''
from math import factorial as f

mod = 10**9 + 7

n, m = map(int, input().split())


def C(n, k):
    return f(n) // (f(k) * f(n - k))


print(int(C(n + 2*m - 1, 2*m)) % mod)
