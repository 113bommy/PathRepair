import sys, os
from collections import defaultdict
from math import gcd
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))


def f(n):
    n = abs(n)
    while n:
        if n%10 == 8:return(True)
        n//= 10
    return(False)

def main():
    n = int(input())
    c = 0
    while True:
        if f(n):print(c);return
        n += 1; c += 1







if __name__ == "__main__":
    main()



"""
3 2
1 1
2 2



"""