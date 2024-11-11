import sys
import math
from collections import defaultdict as ddict

fast_inp = lambda: sys.stdin.readline().split('\n')[0]
read_list = lambda: fast_inp().split(' ')
read_listi = lambda: list(map(int, fast_inp().split(' ')))
read_listf = lambda: list(map(float, fast_inp().split(' ')))
read_int = lambda: int(fast_inp())
read_float = lambda: float(fast_inp())
read = lambda: fast_inp()
DEBUG = True


def debug(**kwargs):
    if not DEBUG:
        return
    print('*' * 20)
    for k, v in kwargs.items():
        print(f'\t{k}:{v}\t')
    print('*' * 20)

MOD = int(1e9) + 7
factorial = [1, 1, 2]
for x in range(3, int(1e6) + 10):
    factorial.append(factorial[-1] * x % MOD)



def solve() -> None:
    n = read_int()
    print(factorial[n] - pow(2, n - 1, MOD) % MOD)


t = 1
for _ in range(t):
    solve()