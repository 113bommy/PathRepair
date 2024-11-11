import sys
from collections import deque
input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return (map(int, input().split()))

def digitSum(x):
    c = 0
    while x:
        c += x%10
        x //= 10
    return c


# One platform
def solve(k, numbers):
    if not numbers:
        return 0
    numbers.sort()
    v = deque()

    best = [1 for i in range(len(numbers))]
    overallBest = 0
    for n,i in enumerate(numbers):
        while v and i - k > v[0]:
            v.popleft()
        if not v:
            v.append(i)
        elif i - v[0] <= k:
            v.append(i)
        if n > 0:
            best[n] = max(best[n-1], len(v))
        if n >= len(v):
            overallBest = max(overallBest, len(v) + best[n-len(v)])
        else:
            overallBest = best[n]
    return overallBest

lines = inp()
for i in range(lines):
    v = inlt() #n, k
    w = inlt()
    _ = inlt() # Y coordinates, not needed
    print(solve(v[1], w))
