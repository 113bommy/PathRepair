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
        a,b,c=In()
        q=0
        for i in range(1,10001):
            for j in range(1,10001):
                if ((i*j)==a and (j*c==b*i)):
                    print(i,j)
                    q=1
                    break
            if q==1:
                break
        print(i,j)
        print(4*(i+j+(c//i)))

    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    #for _ in range(I()):main()
    for _ in range(1):main()