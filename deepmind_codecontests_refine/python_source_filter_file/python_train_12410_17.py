from sys import stdin, stdout
import math
from itertools import permutations, combinations
from collections import defaultdict


def L():
    return list(map(int, stdin.readline().split()))


def In():
    return map(int, stdin.readline().split())


def I():
    return int(stdin.readline())


P = 1000000007
from math import sqrt
def div(m):
    l1=[]
    for i in range(1,int(math.sqrt(m))+1):
        if (m%i)==0:
            if (m//i)==i:
                l1.append(i)
            else:
                l1.append(i)
                l1.append(m//i)
    return(l1)
def main():
    try:
            for _ in range(int(input())):
                n,a,b=In()
                l=L()
                l1=L()
                if sum(l)>sum(l1):
                    print('YES')
                else:
                    print('NO')


    except:
        pass


if __name__ == '__main__':
    main()
