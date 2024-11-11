# cook your dish here
from sys import stdin, stdout
import math
from itertools import permutations, combinations
from collections import defaultdict
from bisect import bisect_left 
from bisect import bisect_right
 
def L():
    return list(map(int, stdin.readline().split()))
 
def In():
    return map(int, stdin.readline().split())
 
def I():
    return int(stdin.readline())
 
P = 1000000007
def main():
    arr = [0 for i in range(50001)]
    arr[0]= 2
    sm = arr[0]+3
    for i in range(1, 50001):
        arr[i] = arr[i-1]+sm 
        sm += 3
    for t in range(I()):
        n = I()
        tmp = n
        c = 0
        while n >= 2:
            x = bisect_right(arr, n)
            n -= arr[x-1]
            c += 1 
        print(c)
        
    
    
if __name__ == '__main__':
    main()
