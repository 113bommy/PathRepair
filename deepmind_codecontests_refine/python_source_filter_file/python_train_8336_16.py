from collections import defaultdict
from sys import stdin
input = stdin.readline
import math

def main():
    n = int(input())
    a = list(map(int, input().split()))
    powers2 = [2**i for i in range(2, 31)]
    cnt = defaultdict(int)
    for val in a:
        cnt[val] += 1

    res = 0
    for k in cnt:
        found = False
        for pow2 in powers2:
            if pow2 > k:
                aj = pow2-k
                if aj in cnt and (cnt[aj] >= 2 or aj != k):
                    found = True
                    break
        if not found:
            res += 1
    print(res)


if __name__ == '__main__':
    main()