from sys import stdin, stdout
import math,sys
from itertools import permutations, combinations
from collections import defaultdict,deque,OrderedDict
from os import path
import bisect as bi
import heapq 
def yes():print('YES')
def no():print('NO')
if (path.exists('input.txt')): 
    #------------------Sublime--------------------------------------#
    sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
    def I():return (int(input()))
    def In():return(map(int,input().split()))
else:
    #------------------PYPY FAst I/o--------------------------------#
    def I():return (int(stdin.readline()))
    def In():return(map(int,stdin.readline().split()))


def main():
    try:
        k,n,w=In()
        t=((((w+1)*w)//2)*k)-n
        if n<=0:
            print(0)
        else:
            print(t)
        

    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    #for _ in range(I()):main()
    for _ in range(1):main()