import sys, math
from itertools import permutations

DEBUG = 0
if DEBUG:
    f = open("input.txt", "r")
    input = f.readline
else:
    input = sys.stdin.readline

def mp():
    return list(map(int, input().split()))

def main():
    n = int(input())
    c = 0
    while n:
        n /= 2
        c += 1
    print(c)
main()