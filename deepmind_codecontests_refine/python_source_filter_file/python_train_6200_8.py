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
if (debug):
    test_count = int(input())

for t in range(test_count):
    N = inp()
    A = inlt()
    value_map = {}
    for x in A:
        if x in value_map:
            value_map[x] = value_map[x] + 1
        else:
            value_map[x] = 1
    two_power = []
    curr = 1
    while curr <= 1000000000:
        two_power.append(curr)
        curr *= 2
    # print(two_power)
    # print(value_map)
    total = 0
    for x in value_map.keys():
        x_count = value_map[x]
        for p in two_power:
            if x < p:
                diff = p - x
                if diff >= x and diff in value_map:
                    if diff == x:
                        total += (x_count * (x_count - 1)) // 2
                    else:
                        total += (x_count * value_map[diff])
    print(total)
