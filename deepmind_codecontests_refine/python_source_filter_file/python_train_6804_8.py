from collections import deque, defaultdict
from math import sqrt, ceil, factorial, floor, inf, log2, sqrt
import bisect
import copy
from itertools import combinations
import sys
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

for _ in range(1):


            n,k=get_ints()
            a=get_array()
            a.sort()
            b=copy.deepcopy(a)
            for i in range(1,n):
                b[i]+=b[i-1]
            li=[]
            for i in range(len(a)):
                ele=a[i]
                l=i-1
                r=0
                maxi=1
                while(r<=l):
                    mid=(l+r)//2
                    ans=(i-mid)*ele
                    ans-=b[i-1]
                    if mid!=0:
                        ans-=b[mid-1]
                    if ans<=k:
                        maxi=max(maxi,i-mid+1)
                        l=mid-1
                    else:
                        r=mid+1

                li.append([maxi,-ele])
            ##print(li)
            li.sort(reverse=True)
            print(li[0][0],-li[0][1])

