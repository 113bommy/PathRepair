# import collections
# import random
# import math
# import itertools
# import math
# mport math
# from collections import defaultdict
# import itertools
# from sys import stdin, stdout
# import math
# import math
import sys

# import bisect
# import operator
# from decimal import Decimal

# sys.setrecursionlimit(10**6)

p2D = lambda x: print(*x, sep="\n")


def II(): return int(sys.stdin.buffer.readline())


def MI(): return map(int, sys.stdin.buffer.readline().split())


def LI(): return list(map(int, sys.stdin.buffer.readline().split()))


def LLI(rows_number): return [LI() for _ in range(rows_number)]


def BI(): return sys.stdin.buffer.readline().rstrip()


def SI(): return sys.stdin.buffer.readline().rstrip().decode()


def li(): return [int(i) for i in input().split()]


def lli(rows): return [li() for _ in range(rows)]


def si(): return input()


def ii(): return int(input())


def ins(): return input().split()

facts = [1]*200010
mod = 998244353

for i in range(2,200010):
    facts[i] = (facts[i-1]*i)%mod

#print(facts[:20])
def solve():
    n = II()
    a = LI()
    b = sorted(a)
    #print(b)
    cb = b.count(b[-1])
    if cb>1:
        return facts[n]
    else:
        p = b.count(b[-2])
        if b[-1]-b[-2]>1:
            return 0
        if n == 2:
            return 1
        #print(facts[n])
        res = 1
        for i in range(p+2,n+1):
            res= (res*i)%mod
        return facts[n]- (res*facts[p])%mod

def main():
    #print('finish '+ str(solve()), flush=True)
    for _ in range(II()):
        sys.stdout.write(str(solve()) + "\n")

    #     z += str(ans) + '\n'
    # print(len(ans), ' '.join(map(str, ans)), sep='\n')
    # stdout.write(z)


# for interactive problems
# print("? {} {}".format(l,m), flush=True)
# or print this after each print statement
# sys.stdout.flush()


if __name__ == "__main__":
    main()