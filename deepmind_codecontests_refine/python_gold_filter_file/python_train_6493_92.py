from collections import deque
from collections import OrderedDict
import math
 
import sys
import os
from io import BytesIO
import threading
import bisect

import operator
 
import heapq

#sys.stdin = open("F:\PY\\test.txt", "r")
input = lambda: sys.stdin.readline().rstrip("\r\n")


def getLucky(limit):
    ar = [0]*5000
    ar[0], ar[1] = 4,7
    p2 = 1
    idx =0
    while(idx<=limit):
        if 4*(10**p2)>limit:
            break
        for idx in range(idx, idx+2**p2):
            ar[idx+2**p2]=4*(10**p2)+ar[idx]
            ar[idx+(2**p2)*2]=7*(10**p2)+ar[idx]
        idx+=1
        p2+=1
    return ar

a = int(input())
answer = 0
lPass =0
for i in range(a, 0, -1):
    #print(i, lPass)
    answer+=i+lPass*(i-1)
    lPass+=1
print(answer)
