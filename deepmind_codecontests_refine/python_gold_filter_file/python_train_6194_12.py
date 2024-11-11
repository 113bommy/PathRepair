import math
import itertools

import os
import sys

n = int(input())
A = sorted(map(int, input().split()))

if A[0] == 1:
    print("-1")
else:
    print("1")