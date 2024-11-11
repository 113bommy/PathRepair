import os

import sys

debug = True

if debug and os.path.exists("input.in"):
    input = open("input.in", "r").readline
else:
    debug = False
    input = sys.stdin.readline


def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return s[:len(s) - 1]  # Remove line char from end


def invr():
    return (map(int, input().split()))


test_count = 1
if debug:
    test_count = inp()

for t in range(test_count):
    if debug:
        print("Test Case #", t + 1)
    # Start code here
    n = inp()
    a = inlt()
    a.reverse()
    max_c = 1000001
    ans = 0
    for x in a:
        local_max = max(0, min(x, max_c - 1))
        max_c = local_max
        ans += local_max

    print(ans)
