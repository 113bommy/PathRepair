
import collections
import math
import itertools
import  sys
import time

def fast_input():
    return sys.stdin.readline().strip()

input = fast_input

def ints_input():
    return list(int(x) for x in input().split())

def int_input():
    return int(input())



def solve():
    s, n = ints_input()
    digits = [int(d) for d in str(s)]
    while sum(digits) < n:
        i = len(digits) - 2
        while digits[i] == 0:
            i -= 1
        digits[i] -= 1
        digits[i+1] += 10
    answers = [0 for _ in range(n)]
    done = 0
    for i, d in enumerate(digits[::-1]):
        left = d
        for _ in range(d):
            while done < n:
                answers[done] += 10**i
                done += 1
                left -= 1
        answers[0] += left*10**i
    print(' '.join([str(x) for x in answers]))




if True:
    for _ in range(int_input()):
        solve()
else:
    solve()