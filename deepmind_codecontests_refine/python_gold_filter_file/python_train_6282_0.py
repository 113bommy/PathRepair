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
    n, m = map(int, In().split())

    a = list(map(int, In().split()))
    b = list(map(int, In().split()))
    
    #print(a)
    #print(b)
    
    if(n > m):
        if(a[0]*b[0] >= 0):
            print("Infinity")
        else:
            print("-Infinity")
    elif(n < m):
        print("0/1")
    else:
        GCD = gcd(a[0], b[0])
        print(str(a[0]//GCD) + '/' + str(b[0]//GCD))
    
if __name__ == '__main__':
    main()
