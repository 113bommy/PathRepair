import itertools
import math
from collections import defaultdict

def input_ints():
    return list(map(int, input().split()))

def solve():
    n, m = input_ints()
    s = []
    for i in range(n):
        s.append(input())
    for d in range(60, -1, -1):
        for x, y in itertools.product(range(d, n - d + 1), range(d, m - d + 1)):
            ok = True
            for i in range(x - d, x + d + 1):
                if s[i][y - d:y + d + 1].count('B') != 2 * d + 1:
                    ok = False
                    break
            if ok:
                print(x + 1, y + 1)
                return

if __name__ == '__main__':
    solve()
