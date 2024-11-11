from sys import stdin
from collections import deque
import math
input=stdin.readline

factorsList = [0 for j in range(10001)]
for i in range(1, 10001):
    leftDeque = deque()
    rightDeque = deque()
    for j in range(1, math.floor(math.sqrt(i)) + 1):
        if i % j == 0:
            leftDeque.append(j)
            rightDeque.appendleft(i//j)
    if math.sqrt(i) == rightDeque[0]:
        rightDeque.popleft()
    factorsList[i] = leftDeque + rightDeque

def getOptimalC(b,c):
    if c% b == 0:
        return c
    mod = c % b
    if mod <= b - mod:
        return c - mod
    else:
        return c + b - mod

def getOptimalA(a,b):
    ind = -1
    for e in range(len(factorsList[b])):
        if factorsList[b][e] == a:
            return a
        if factorsList[b][e] > a:
            ind = e
            break
    lower = factorsList[b][e - 1]
    higher = factorsList[b][e]
    if (a - lower) < (higher - a):
        return lower
    else:
        return higher
    

t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    lowestTing = 30000
    lowestTrio = [-1,-1,-1]
    for i in range(1, 10001 ):
        d = getOptimalC(i, c)
        e = getOptimalA(a, i)
        if abs(e - a) + abs(i - b) + abs(d - c) < lowestTing:
            lowestTing = abs(e - a) + abs(i - b) + abs(d - c)
            lowestTrio = [e, i, d]
    print(lowestTing)
    print(*lowestTrio)


