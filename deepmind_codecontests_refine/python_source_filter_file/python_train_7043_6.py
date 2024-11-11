# Author: Sudam Kalpage
# College: University of Peradeniya
# Date: 15/11/2020
# Contact: sudamkalpag4@gmail.com
from math import *
from itertools import permutations
from itertools import combinations
from itertools import combinations_with_replacement
import copy
def ii(): return int(input())
def si(): return input()
def mi(): return map(int, input().split())
def li(): return list(mi())  # a=[int(x) for x in input().split()]

def Function():
    w,l = li()
    a= li()
    a.reverse()
    s=sum(a[:l])
    min=s
    for i in range(l,w-1):
        print(s)
        # print(i)
        s+=a[i]
        s-=a[i-l]
        if s<min:
            min=s
    print(min)

for _ in range(1):
# for _ in range(int(input())):
#     print("Case #{}: ".format(_+1),end="")
    Function()
