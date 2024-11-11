import random
import math
from collections import defaultdict
import itertools
from sys import stdin, stdout
import sys
import operator
from decimal import Decimal


# sys.setrecursionlimit(1500000000)

def call(a, pos, x):
    p = 1
    while a[pos] * p < x:
        if pos > 0:
            pos -= 1
            p += 1
        else:
            return 0
    if pos > 0:
        cnt = call(a[:pos], pos - 1, x)
    else:
        cnt = 0
    return 1 + cnt


def main():
    # z = ''
    # p = lambda *a: print(*a, flush = True)
    # d = defaultdict()

    mod = 10 ** 9 + 7

    t = int(input())
    for _ in range(t):
        # n = input()
        # c, m, p, v = map(float, input().split())

        n, x = list(map(int, input().split()))
        a = list(map(int, input().split()))
        # s = input()

        a.sort(reverse= True)
        # print(a[0]>x)
        cnt = 0
        for i in range(n):
            if a[i] >= x:
                cnt += 1
            else:
                break
        # print(cnt)
        while i!=n:
            for j in range(i,n):
                prev = a[j]* (j-i+1)
                if prev >= x:
                    cnt += 1
                    i = j+1
                    break
            if j == n-1: break

        print(cnt)


    #    s = input()

    #     z += str(ans) + '\n'
    # stdout.write(z)


# for interactive problems
# print("? {} {}".format(l,m), flush=True)
# or print this after each print statement
# sys.stdout.flush()


if __name__ == "__main__":
    main()