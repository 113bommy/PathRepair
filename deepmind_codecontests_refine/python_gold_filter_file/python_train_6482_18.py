import heapq

from collections import deque
from collections import defaultdict

import sys

sys.setrecursionlimit(100000)

def check(lst):
    for i,a in enumerate(lst):
        if a!=1:
            return False,i
    return True,None

I=lambda : list(map(int,input().split(' ')))
for _ in range(int(input())):
    n=I()[0]
    lst=I()
    b,ind=check(lst)
    if n==1  or (b and n%2==1) or (ind!=None and (ind%2==0)):
        print('First')
    else:
        print('Second')
