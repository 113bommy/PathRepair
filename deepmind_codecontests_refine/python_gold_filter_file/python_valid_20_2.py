
import collections
import math
import itertools
import  sys

def fast_input():
    return sys.stdin.readline().strip()

input = fast_input

def ints_input():
    return list(int(x) for x in input().split())




def solve():
    n, k = ints_input()
    colours = ints_input()
    colours_done = set()
    ranges = []
    while len(colours_done) < n:
        colours_on_pass = dict()
        for i, c in enumerate(colours):
            if c in colours_on_pass:
               ranges.append((c, (colours_on_pass[c], i+1)))
               colours_done.add(c)
               colours_on_pass = dict()
            elif c not in colours_done:
                colours_on_pass[c] = i+1
    for _, r in sorted(ranges):
        print(' '.join([str(x) for x in r]))


if False:
    for _ in range(int(input())):
        solve()
else:
    solve()