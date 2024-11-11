import sys
from collections import *
import math
input = sys.stdin.readline
def rotate(s,k):
    s = s[::-1]
    x = s[k:][::-1]
    y = s[:k][::-1]
    return y+x

s = input()[:-1]
q = int(input())
while q:
    q-=1
    l,r,k = [int(x) for x in input().split()]
    l-=1
    x = s[:l]
    y = rotate(s[l:r],k)
    z = s[r:]
    s = x+y+z
print(s)
