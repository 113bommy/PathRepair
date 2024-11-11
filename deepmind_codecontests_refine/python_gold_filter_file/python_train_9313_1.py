import sys
import math
from collections import defaultdict
import itertools

MAXNUM = math.inf
MINNUM = -1 * math.inf


def getInts():
    return map(int, sys.stdin.readline().rstrip().split(" "))


def getString():
    return sys.stdin.readline().rstrip()


def printOutput(ans):
    sys.stdout.write()  # add to me
    pass


def solve():
    pass


def readinput():
    students = int(sys.stdin.readline().rstrip())
    idNumbers = {}
    singles = set()

    for _ in range(students):
        prev, nxt = getInts()
        if prev not in idNumbers:
            singles.add(prev)
            idNumbers[prev] = [0, nxt]

        else:
            singles.remove(prev)
            idNumbers[prev][1] = nxt

        if nxt not in idNumbers:
            idNumbers[nxt] = [prev, 0]
            singles.add(nxt)
        else:
            singles.remove(nxt)
            idNumbers[nxt][0] = prev
    ans = list(singles)
    if idNumbers[ans[0]][0] == 0:
        start = ans[0]
    else:
        start = ans[1]
    second = idNumbers[0][1]

    ans = []
    ans.append(start)
    ans.append(second)

    cur1 = start
    cur2 = second
    while idNumbers[cur1][1] != 0 or idNumbers[cur2][1] != 0:
        if idNumbers[cur1][1] != 0:
            cur1 = idNumbers[cur1][1]
            ans.append(cur1)
        if idNumbers[cur2][1] != 0:
            cur2 = idNumbers[cur2][1]
            ans.append(cur2)

    if len(idNumbers) == 3:
        ans = [idNumbers[0][0], idNumbers[0][1]]

    for ele in ans:
        print(ele, end=" ")


readinput()
