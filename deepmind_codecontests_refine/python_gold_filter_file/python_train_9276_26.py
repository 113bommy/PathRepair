import sys
import math
import bisect
import itertools
import random

def main():
    n = int(input())
    for i in range(n):
        if i == 0:
            s = set(map(int, input().split()[1:]))
        else:
            s &= set(map(int, input().split()[1:]))
    print(' '.join(list(str(a) for a in s)))

if __name__ == "__main__":
    main()
