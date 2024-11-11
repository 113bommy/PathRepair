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
    sys.stdout.write(str(ans) + "\n")  # add to me


def dfsEquals(aList, bList, aPos, bPos):
    if bPos < 0:
        return True, -1  # this means that the number should be returned exactly as is
    if aList[aPos] > bList[bPos]:
        return False, 0
    if aList[aPos] == bList[bPos]:
        return dfsEquals(aList, bList, aPos - 1, bPos - 1)
    return True, bPos  # where do we start


def null(a, b):
    aList = []
    while a > 0:
        nextDigit = a % 10
        aList.append(nextDigit)
        a //= 10

    bList = []
    while b > 0:
        nextDigit = b % 10
        bList.append(nextDigit)
        b //= 10

    bPos = 0
    start = len(bList) - 1
    for i in range(start, len(aList)):
        isValid, delInd = dfsEquals(aList, bList, i, start)
        print(isValid, delInd)
        if isValid:
            if delInd == -1:
                return aList

            for j in range(0, i - (len(aList) - delInd)):
                aList[j] = 0
            for j in range(0, delInd + 1):
                aList[j] = bList[j]
            aList[i] = bList[-1]
            return aList


def isB(num, b):
    n1 = str(num)
    b2 = str(b)
    bPos = 0
    craftedString = ""
    for ele in n1:
        if ele == "4" or ele == "7":
            craftedString += ele
    return craftedString == b2


def solve(a, b):
    if a < b:
        return b
    for nextNum in range(a + 1, a * 100, 1):
        if isB(nextNum, b):
            return nextNum


def readinput():
    a, b = getInts()
    printOutput(solve(a, b))


readinput()
