import math,string,itertools,fractions,heapq,collections,re,array,bisect
from itertools import chain, dropwhile, permutations, combinations
from collections import defaultdict


def main(n,s):
    s.sort()
    curr = 0
    ans = 0
    for x in s:
        if x >= curr:
           ans += 1
           curr += x
    print(ans)


def main_input(info=0):
    n = int(input())
    t = list(map(int,input().split()))
    main(n,t)

if __name__ == "__main__":
    main_input()
