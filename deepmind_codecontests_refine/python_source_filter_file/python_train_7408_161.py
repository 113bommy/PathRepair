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
    n=int1()
    if n==1:
        print(0)
    else:
        if n%2==0:
            print((3*n)//3)
        else:
            print(0)








if __name__ == "__main__":
    main()
