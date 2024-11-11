# ///==========Libraries, Constants and Functions=============///
#mkraghav
import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

def int1():return int(input())

import string

import math

from itertools import combinations
# ///==========MAIN=============///


def main():
    n,k=get_array()
    a=get_array()
    b=[]
    for i in a:
        b.append(i)
    s=0
    i=0
    l=[]
    while i<len(a):
        s=s+a[i]
        if s<=k:
            l.append(a[i])
            a[i]=0
        i=i+1
    l.sort(reverse=True)
    

    i=0
    while i<n:

        if a[i]!=0:
            m=0

            s1=sum(b[:i+1])

            j=0
            y1=0


            while j<len(l):
                m=m+l[j]

                if s1-m>=k:
                    y1=y1+1
                if s1-m<k:
                    y1=y1+1
                    break



                j=j+1


            a[i]=y1
            l.append(b[i])
            l.sort(reverse=True)
        i=i+1

    print(*a)














if __name__ == "__main__":
    main()
