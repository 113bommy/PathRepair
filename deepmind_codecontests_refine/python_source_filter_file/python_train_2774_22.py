import math
import os
import random
import re
import sys
import functools
from operator import itemgetter, attrgetter
from collections import Counter

if __name__ == '__main__':
    Y = lambda: list(map(int, input().split()))
    P = lambda: map(int, input().split())
    N = lambda: int(input())

    n, k = P()
    a = Y()
    p = 0

    for i in range(k):
        if n % a[i] < n % a[p]:
            p = i
    print("%s %s" % (p + 1, int(n / a[p])))