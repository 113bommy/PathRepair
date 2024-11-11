import atexit
import io
import sys
import os

from bisect import *
from collections import *
from fractions import gcd
from fractions import Fraction as fr_
from itertools import *
import math

inf = float('inf')  # sys.maxint in py2
inf_neg = float('-inf')  # sys.maxsize = 9*1e18
range_5 = int(1e5 + 1)
range_6 = int(1e6 + 1)
range_7 = int(1e7 + 1)
range_8 = int(1e8 + 1)
# sys.setrecursionlimit(range_8)

# fast io
_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


def main():
    # code here
    n, m = map(int,input().split())
    # ll = list(map(int, input().split()))
    ll = []
    for _ in range(n):
    	a, b = map(int, input().split()) 
    	ll.append(a/(b*m))
    # print("{}".format())
    print(min(ll))


if __name__ == '__main__':
    main()
