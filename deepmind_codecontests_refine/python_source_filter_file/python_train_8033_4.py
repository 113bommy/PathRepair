import sys
import math
import bisect
import re

def solve(n):
    val = 0
    for i in range(0, 10 ** 18):
        val += i
        if val >= n and (val - n) % 2 == 0:
            return i
    return -1

def main():
    n = int(input())
    print(solve(n))

if __name__ == "__main__":
    main()
