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
    moves = input()
    locations = set()

    currX = 0
    currY = 0
    locations.add((0, 0))
    ans = "OK"
    for x in moves:
        last = (currX, currY)
        if x == "L":
            currX -= 1
        elif x == "R":
            currX += 1
        elif x == "D":
            currY -= 1
        else:
            currY += 1
        curr = (currX, currY)
        # print(locations)
        # print(last, curr)
        if curr in locations or ((currX - 1, currY) != last and (currX - 1, currY) in locations) or (
                (currX + 1, currY) != last and (currX + 1, currY) in locations) or (
                (currX, currY + 1) != last and (currX, currY + 1) in locations) or (
                (currX, currY - 1) != last and (currX, currY - 1) in locations):
            ans = "BUG"
            break

        locations.add(curr)
    print(ans)
