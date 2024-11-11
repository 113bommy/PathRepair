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
    return (list(s[:len(s) - 1]))


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
    ans = False
    for i in range(1, 25):
        if (i * (i + 1)) // 2 == n:
            ans = True
    print("YES" if ans else "NO")
