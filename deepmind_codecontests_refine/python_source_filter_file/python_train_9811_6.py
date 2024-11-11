from sys import *
import collections
import math

from bisect import bisect_left

def take_closest(myList, myNumber):
    """
    Assumes myList is sorted. Returns closest value to myNumber.

    If two numbers are equally close, return the smallest number.
    """
    pos = bisect_left(myList, myNumber)
    if pos == 0:
        return myList[0]
    if pos == len(myList):
        return myList[-1]
    before = myList[pos - 1]
    after = myList[pos]
    if after - myNumber < myNumber - before:
       return after
    else:
       return before

t = int(stdin.readline())
for _ in range(t):
    r,g,b = list(map(int,stdin.readline().split(' ')))
    nr = list(map(int,stdin.readline().split(' ')))
    ng = list(map(int,stdin.readline().split(' ')))
    nb = list(map(int,stdin.readline().split(' ')))
    nr.sort()
    ng.sort()
    nb.sort()
    mn =  math.inf
    for wg in ng:
        wr = take_closest(nr,g)
        wb = take_closest(nb,g)
        res = (wg-wr)**2+(wg-wb)**2+(wr-wb)**2
        if(mn > res):
            mn = res
    for wg in nr:
        wr = take_closest(nb,g)
        wb = take_closest(ng,g)
        res = (wg-wr)**2+(wg-wb)**2+(wr-wb)**2
        if(mn > res):
            mn = res
    for wg in nb:
        wr = take_closest(nr,g)
        wb = take_closest(ng,g)
        res = (wg-wr)**2+(wg-wb)**2+(wr-wb)**2
        if(mn > res):
            mn = res
    print(mn)
