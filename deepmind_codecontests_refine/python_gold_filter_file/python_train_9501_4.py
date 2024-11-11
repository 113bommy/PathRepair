from fractions import Fraction
import bisect
import os
import io
from collections import Counter
import bisect
from collections import defaultdict
import math
import random
import heapq 
from math import sqrt
import sys
from functools import reduce, cmp_to_key
from collections import deque
import threading
from itertools import combinations
from io import BytesIO, IOBase
from itertools import accumulate
from queue import Queue


# sys.setrecursionlimit(200000)
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def input():
    return sys.stdin.readline().strip()


def iinput():
    return int(input())


def tinput():
    return input().split()


def rinput():
    return map(int, tinput())


def rlinput():
    return list(rinput())


mod = int(1e9)+7


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


# ----------------------------------------------------
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')



t = 1
t = iinput()
for _ in range(t):
    n = iinput()
    s = list(input())
    if n == 1 or n == 2:
        print(0)
    else:
        cnt = s.count('L')
        if cnt == n or cnt == 0:
            print(1+(n-1)//3)
            continue
        ans = 0
        i = 1
        temp = 1
        while i < n and s[i] == s[i - 1]:
            i += 1
            temp += 1
        j = n - 1
        while j > i and s[j] == s[0]:
            j -= 1
            temp += 1
        # print(temp,i,j)
        ans = (temp)//3

        while i < j:
            temp = 1
            while i < j and s[i] == s[i +1]:
                temp += 1
                i += 1
            i += 1
            # print(temp)
            ans += (temp) // 3
            # print("ANs",ans)
        print(ans)

                
            
            
                
            
                
            

        


    
        
        

