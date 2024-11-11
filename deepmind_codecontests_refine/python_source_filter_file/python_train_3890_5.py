import math
import sys
import collections
import bisect
#import string
import time
def get_ints():return map(int, sys.stdin.readline().strip().split())
def get_list():return list(map(int, sys.stdin.readline().strip().split()))
def get_string():return sys.stdin.readline().strip()
def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1  # y = y/2
        x = (x * x) % p
    return res
for tc in range(1):
    n,m=get_ints()
    ans=power(3,n,m)
    if ans==0:
        print(m-1)
    else:
        print(ans)