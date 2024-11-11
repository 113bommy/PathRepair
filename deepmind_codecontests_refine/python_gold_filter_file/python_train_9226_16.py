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
    INF = int(1e9)
    n = int(input())
    for i in range(n):
        x = int(input())
        if x > 3 * 7 - 10:
            print("YES")
        elif x % 3 == 0 or x == 7 or x == 10:
            print("YES")
        else:
            print("NO")
main()