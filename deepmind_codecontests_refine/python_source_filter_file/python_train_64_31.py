import bisect
import collections
import copy
import functools
import heapq
import itertools
import math
import random
import re
import sys
import time
import string
from typing import List
sys.setrecursionlimit(999999)

l = 1
r = 10**6
m = (l+r)>>1
n = int(input())
arr = list(map(int,input().split()))
arr.sort()
j = bisect.bisect_left(arr,m)
if j==0:
    print(r-arr[j])
elif j== n:
    print(arr[j-1]-1)
else:
    print(max(arr[j-1]-1,r-arr[j]))
