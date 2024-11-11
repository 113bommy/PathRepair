#***************55B - Smallest number***************#
#author: @Divyesh Chhabra

from math import *
import os
import random
import re
import sys
from itertools import *

m = pow(10,9)+7

n = list(map(int,input().split()))
s = input()
n.sort()

mul = 0
add = 0

for i in s:
    if i == '*':
        mul += 1
    else:
        add += 1

if mul == 0:
    print(n[0]+n[1]+n[2]+n[3])
elif mul == 3:
    print(n[0]*n[1]*n[2]*n[3])
elif mul == 2:
    if s == '* * +':
        print(min(n[3]+n[1]*n[2]*n[0],n[0]*n[1]+n[2]*n[3],n[0]*n[2]+n[1]*n[3],n[0]*n[3]+n[1]*n[3]))
    elif s == '* + *':
        print(n[0]*(n[1]*n[2]+n[3]))
    else:
        print(n[0]*n[1]*(n[2]+n[3]))
else:
    if s == '+ + *':
        print((n[1]+n[2]+n[3])*n[0])
    elif s == '+ * + ':
        print(min((n[1]+n[2])*n[0]+n[3]),n[0]*n[1]+n[2]+n[3])
    else:
        print(n[0]*n[1]+n[3]+n[2])
        