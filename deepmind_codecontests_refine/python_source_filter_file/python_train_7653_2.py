from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *

Input = []

#stdin = open('in', 'r')
#stdout = open('out', 'w')

## for i, val in enumerate(array, start_i_value)

def Out(x):
    stdout.write(str(x) + '\n')

def In():
    return stdin.readline().strip()

def inputGrab():
    for line in stdin:
        Input.extend(map(str, line.strip().split()))
'''--------------------------------------------------------------------------------'''


def main():
    n, k = map(int, In().split())
    v = list(map(int, In().split()))
    
    #print(v)
    rank = [0 for i in range(101)]
    
    for val in v:
        rank[val] += 1
    
    coin = 0
    #print(rank[1:k+1])
    
    while(rank[k] != n):
        coin += 1
        for i in range(k, 0, -1):
            if(rank[i] and i != k):
                rank[i] -= 1
                rank[i+1] += 1
        
        print(rank[1:k+1])
        
    
    print(coin)
    
if __name__ == '__main__':
    main()
