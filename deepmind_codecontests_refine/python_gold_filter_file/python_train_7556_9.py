import sys
import math
import bisect
import itertools
import random
import re

def main():
    n = int(input())
    tmp = 1
    while tmp * 10 <= n:
        tmp *= 10
    ans = n // tmp * tmp + tmp - n
    print(ans)

if __name__ == "__main__":
    main()
