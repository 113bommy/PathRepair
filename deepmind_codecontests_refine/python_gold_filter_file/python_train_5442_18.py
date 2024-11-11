from __future__ import division, print_function
import bisect
import math
import heapq
import itertools
import sys
from collections import deque
from atexit import register
from collections import Counter
from functools import reduce

if sys.version_info[0] < 3:
    from io import BytesIO as stream
else:
    from io import StringIO as stream


def sync_with_stdio(sync=True):
    """Set whether the standard Python streams are allowed to buffer their I/O.
 
    Args:
        sync (bool, optional): The new synchronization setting.
 
    """
    global input, flush

    if sync:
        flush = sys.stdout.flush
    else:
        sys.stdin = stream(sys.stdin.read())
        input = lambda: sys.stdin.readline().rstrip('\r\n')

        sys.stdout = stream()
        register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


for _ in range(int(input())):
    n = input()
    a = list(input())
    ec = 0
    oc = 0
    z = len(a)

    if z % 2 == 0:
        for i in range(z):
            if i % 2 != 0:
                if int(a[i]) % 2 == 0:
                    ec += 1
                    break
        if ec == 1:
            print(2)
        else:
            print(1)
    else:
        for i in range(z):
            if i % 2 == 0:
                if int(a[i]) % 2 != 0:
                    oc += 1
                    break
        if oc == 1:
            print(1)
        else:
            print(2)
