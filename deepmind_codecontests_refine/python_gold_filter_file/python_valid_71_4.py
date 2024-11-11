import sys
input = sys.stdin.readline
# sys.setrecursionlimit(400000)
def I(): return input().strip()
def II(): return int(input().strip())
def LI(): return [*map(int, input().strip().split())]
import copy, string, math, time, functools, random, fractions
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter, OrderedDict
from itertools import permutations, combinations, groupby
from operator import itemgetter
from itertools import chain, combinations


def greater(num, men, mex):
    res = []
    flag = False
    num = str(num)
    i = 0
    while i < len(str(num)):
        if flag:
            res.append(str(men))
        else:
            if men > int(num[i]):
                res.append(str(men))
                flag = True
            elif men == int(num[i]):
                res.append(str(men))
            elif mex > int(num[i]):
                res.append(str(mex))
                flag = True
            elif mex == int(num[i]):
                res.append(str(mex))
            else:
                while res:
                    pop = res.pop()
                    i -= 1
                    if pop != str(mex):
                        res.append(str(mex))
                        flag = True
                        break
                if not res:
                    return False
        i += 1
    return ''.join(res)


for _ in range(II()):
    inp, k = LI()
    inp = str(inp)
    if k == 1:
        size = len(inp)
        for i in range(10):
            s = ''.join([str(i) for x in range(size)])
            if int(inp) <= int(s):
                print(int(s))
                break
    else:
        ans = float('inf')
        for i in range(10):
            for j in range(i, 10):
                temp = greater(inp, i, j)
                if temp is not False:
                    ans = min(ans, int(temp))
        print(ans)





