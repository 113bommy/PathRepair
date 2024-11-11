import io
import os
from collections import defaultdict
from sys import stdin, stdout
#input = stdin.readline

from math import gcd

def main():
    n, m = map(int, input().split())
    if m == 0:
        print(1 if n > 0 else 0)
    else:
        if m <= n // 2:
            print(m)
        else:
            print(n-m)


if __name__ == '__main__':
    main()
