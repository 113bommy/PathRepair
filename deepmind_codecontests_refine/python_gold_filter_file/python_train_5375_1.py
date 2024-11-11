#This code is contributed by Siddharth
from bisect import *
import math
from collections import *
from heapq import *
from itertools import *
inf=10**18
mod=10**9+7






# ==========================================Code Starts Here=====================================================================


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

#
def lcm(a, b):
    return (a * b) // gcd(a, b)


a,b=map(int,input().split())
temp=lcm(a,b)
if abs(temp//a-temp//b)<=1:
    print("Equal")
elif a<b:
    print("Dasha")
else:
    print("Masha")