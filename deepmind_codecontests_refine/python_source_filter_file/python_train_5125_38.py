from math import *
import sys, random

def nextInt():
    return int(input())
def nextStrs():
    return input().split()
def nextInts():
    return list(map(int,nextStrs()))

def main():
    t = nextInt()

    while t > 0:
        n,d = nextInts()
        arr = nextInts()
    
        for i in range(1,n):
            arr[0] += min(arr[i],d//(i+1))
            d -= min(arr[i],d//(i+1))

        print(arr[0])
            
        t-=1
    
if __name__ == '__main__':
    exit(main())

