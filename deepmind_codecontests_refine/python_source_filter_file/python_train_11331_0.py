import sys
sys.setrecursionlimit(10000000)
def input():
    return sys.stdin.readline()[:-1]
from bisect import *
from collections import *
from heapq import *
from math import *
from itertools import *

def arc079():
    K = int(input())
    k = K//50
    a = [i+k*50 for i in range(50)]
    for i in range(K-k):
        a[i] += 51
    for i in range(50):
        a[i] -= K-k
    print(50)
    print(*a)

arc079()