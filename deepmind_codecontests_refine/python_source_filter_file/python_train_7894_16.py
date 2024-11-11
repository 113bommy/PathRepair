from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, gcd, factorial
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = 10 ** 10
MOD = 10 ** 9 + 7

def main():
    N, M = map(int, input().split())
    diff = abs(N - M)
    if diff > 1:
        print(0)
        return

    ans = 2 if diff == 0 else 1
    for i in range(1, N + 1):
        ans = (ans * i) % MOD
    for i in range(1, M + 1):
        ans = (ans * i) % MOD
    print(ans)


if __name__ == '__main__':
    main()
