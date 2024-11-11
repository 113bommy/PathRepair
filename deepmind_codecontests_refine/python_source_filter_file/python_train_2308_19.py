# Chaitanya Bhutada 
import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys

F = list(map(int,input().split()))
x = F[3]
F.pop()
F.sort()
y = max(0,x-(F[1] - F[0]))
z = max(y , x-(F[2] - F[1]))
print(z)
