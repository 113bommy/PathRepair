import sys
import math
from collections import defaultdict

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
    sys.stdout.write(str(ans) + "\n")


def solve(startCheck, endCheck, x):

    bestCost = [math.inf for _ in range(x + 1)]
    mn = math.inf
    for sweepPos in range(2, 200001):
        for node in startCheck[sweepPos]:
            li, ri, cost = node
            duration = ri - li + 1
            if duration < x:
                bestPair = bestCost[x - duration] + cost
                mn = min(mn, bestPair)
        for node in endCheck[sweepPos]:
            li, ri, cost = node
            duration = ri - li + 1
            if duration < x:
                bestCost[duration] = min(bestCost[duration], cost)

    if mn == math.inf:
        return -1
    return mn


def readinput():
    n, x = getInts()
    startCheck = defaultdict(list)
    endCheck = defaultdict(list)
    for _ in range(n):
        li, ri, costi = getInts()
        startCheck[li].append((li, ri, costi))
        endCheck[ri].append((li, ri, costi))

    printOutput(solve(startCheck, endCheck, x))


readinput()
