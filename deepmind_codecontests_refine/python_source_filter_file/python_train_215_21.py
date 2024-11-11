from sys import stdin
from collections import deque,Counter
import sys
import math
import operator
import random
from fractions import Fraction
import functools

n,s = map(int,input().split())
arr = list(map(int,input().split()))
arr.sort()
num = arr[n//2]
ind = n//2
ans = 0
for i in range(0,ind):
    if arr[i]>s:
        ans+=arr[i]-s
for i in range(ind,n):
    if arr[i]<s:
        ans+=s-arr[i]
print(ans)

