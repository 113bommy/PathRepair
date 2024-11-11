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
    test_count = int(input())

for t in range(test_count):
    if debug:
        print("Test Case #", t + 1)
    # Start code here
    n = inp()
    b = inp()
    g = inp()
    ans = 0
    for i in range(0, n + 1):
        if i <= b and (n - i) <= g:
            ans += 1

    print(ans)
