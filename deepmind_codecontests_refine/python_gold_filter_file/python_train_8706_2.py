'''input
4 2 3
'''
from collections import defaultdict as dd
from collections import Counter as ccd
from itertools import  permutations as pp
from itertools import combinations as cc
from random import randint as rd
from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq as hq
from math import gcd
'''
Author : dhanyaabhirami
Hardwork beats talent if talent doesn't work hard
'''
'''
Stuck?
See github resources
Derive Formula
Kmcode blog
CP Algorithms Emaxx
'''
mod=pow(10,9) +7
def inp(flag=0):
    if flag==0:
        return list(map(int,input().strip().split(' ')))
    else:
        return int(input())

# Code credits
# assert(debug()==true)
# for _ in range(int(input())):

k1,k2,k3=inp()
possible = False
l=sorted([k1,k2,k3])
if 1 in l:
	possible=True
elif l.count(2)>=2:
	possible=True
elif l==[2,4,4] or l==[3,3,3]:
	possible=True

if possible:
	print("YES")
else:
	print("NO")

    