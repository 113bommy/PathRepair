import sys
import math

MAXNUM = math.inf
MINNUM = -1 * math.inf
ASCIILOWER = 97
ASCIIUPPER = 65


def getInt():
    return int(sys.stdin.readline().rstrip())


def getInts():
    return map(int, sys.stdin.readline().rstrip().split(" "))


def getString():
    return sys.stdin.readline().rstrip()


def printOutput(ans):
    for ele in ans:
        sys.stdout.write(str(ele) + "\n")


def fac(g):
    if g == 2:
        return [2]
    facs = []
    MAX = math.sqrt(g) + 1
    cur = 2
    while cur < MAX:
        if g % cur == 0:
            facs.append(cur)
            facs.append(g // cur)
        cur += 1
    facs.append(g)
    return facs


def binsearch(lst, low, high):
    l = 0
    r = len(lst) - 1 
    while l <= r:
        m = (l + r) // 2
        if lst[m] > high:
            r = m - 1
        else:  # if lst[m] <= high
            l = m + 1
    return r


def solve(a, b, queries):
    ans = []
    g = math.gcd(a, b)
    factors = fac(g)
    factors.sort()
    for l, r in queries:
        res = binsearch(factors, l, r)
        if l <= factors[res] <= r:
            ans.append(factors[res])
        else:
            ans.append(-1)
    return ans

def readinput():
    a, b = getInts()
    q = getInt()
    queries = []
    for _ in range(q):
        queries.append(tuple(getInts()))

    printOutput(solve(a, b, queries))

readinput()
