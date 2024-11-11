from math import *
from operator import *
import sys, random

def nextInt():
    return int(input())
def nextStrs():
    return input().split()
def nextInts():
    return list(map(int,nextStrs()))

def main():
    t = 1

    for _ in range(t):
        u,v = nextInts()

        if u > v:
            print(-1)
        elif u == v:
            print('0' if u == 0 else f'1\n{u}')
        else:
            if u%2 != v%2:
                print(-1)
            else:
                div = (v-u)//2
                if (xor(u,div)) == div+u:
                    print(f'2\n{u+div} {xor(u,div)}')
                else:
                    print(f'3\n{u} {div} {div}')
                          
if __name__ == '__main__':
    exit(main())

