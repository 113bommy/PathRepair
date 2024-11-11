""" 
Author: Raj Singh
Date:   11.03.19
"""
from sys import stdin,stdout
#from decimal import *
#import math#import heapq#import operator
#from collections import OrderedDict,Counter,defaultdict
#def getKey(item):return item[0]#l=sorted(l, key=getKey,reverse=True) 
#l= [[0 for x in range(n)] for y in range(n)]#l = [int(i) for i in str(n)]
def inp():
    return int(stdin.readline())
def minp():
    return map(int,stdin.readline().rstrip().split())
def linp():
    return list(minp())
def main():
    n,k=minp()
    move=0
    if k==n:
        move=3*k
    elif k!=1:
        if k<=n/2:
            move+=3*k+k-1
            move+=n-k+n-k+n-k
        else:
            k=n-k+1
            move+=3*k+k-1
            move+=n-k+n-k+n-k
    else:
        move=3*n
    print(move)
            
if __name__=="__main__":
    main()