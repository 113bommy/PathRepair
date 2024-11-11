import os

import sys

debug = False

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
    test_count = int(input())

for t in range(test_count):
    if debug:
        print("Test Case #", t + 1)
    count = 0
    ans = 0
    for s in sys.stdin:
        if s[0] == "+":
            count += 1
        elif s[0] == "-":
            count -= 1
        else:
            ans += len(s.split(":")[1]) * count
    print(ans)
