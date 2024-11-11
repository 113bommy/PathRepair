#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import array
from bisect import *
from collections import *
import fractions
import heapq 
from itertools import *
import math
import random
import re
import string

N = int(input())
c = Counter(map(int, input().split()))
ans = 0
for k, v in c.items():
    if k < v:
        ans = v - k
    elif k > v:
        ans += v
print(ans)
