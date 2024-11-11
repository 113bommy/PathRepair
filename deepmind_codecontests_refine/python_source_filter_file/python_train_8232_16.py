import itertools
import math
from collections import defaultdict

def input_ints():
    return list(map(int, input().split()))

def solve():
    n, h, a, b, k = input_ints()
    for tmp in range(k):
        ta, fa, tb, fb = input_ints()
        if ta == tb:
            ans = abs(fa - fb)
        else:
            ans = 0
            if fa < a:
                ans = a - fa
                fa = a
            elif fa > b:
                ans = fa - b
                fb = b
            ans += abs(ta - tb) + abs(fb - fa)
        print(ans)


if __name__ == '__main__':
    solve()
