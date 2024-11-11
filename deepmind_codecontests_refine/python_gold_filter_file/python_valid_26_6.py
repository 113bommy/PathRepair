import sys
import math
from math import *
import builtins
import collections
input = sys.stdin.readline


def print(x, end='\n'):
    sys.stdout.write(str(x) + end)


# IO helpers
def get_int():
    return int(input())


def get_list_ints():
    return list(map(int, input().split()))


def get_char_list():
    s = input()
    return list(s[:len(s) - 1])


def get_tuple_ints():
    return tuple(map(int, input().split()))


def print_iterable(p):
    print(" ".join(map(str, p)))

def CountFrequency(arr):
    return collections.Counter(arr)  


def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return high
def pow(a,n):
    if n==0:
        return 1
    elif n%2==0:
        return ((pow(a,n//2)%const)*(pow(a,n//2)%const))%const
    else:
        return ((pow(a,n//2)%const)*(pow(a,n//2)%const)*(a%const))%const

def main():
    t=get_int()
    for i in range(t):
        s=get_char_list()
        matches=0
        pointsp1=0
        pointsp2=0
        i=0
        while pointsp1-pointsp2<=math.ceil((10-matches)/2) and i<len(s):
            if i%2==0:
                if s[i]=="1" or s[i]=="?":
                    pointsp1+=1                            
            else:
                if s[i]=="1":
                    pointsp2+=1
            i+=1
            matches+=1
        matches2=0
        poin1=0
        poin2=0
        i=0
        while poin2-poin1<=math.floor((10-matches2)/2) and i<len(s):
            if i%2==0:
                if s[i]=="1" :
                    poin1+=1                            
            else:
                if s[i]=="1" or s[i]=="?":
                    poin2+=1
            i+=1
            matches2+=1
        print(min(matches,matches2))
    pass

if __name__ == '__main__':
    main()