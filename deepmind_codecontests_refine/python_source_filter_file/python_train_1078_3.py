from fractions import gcd
from random import randint


if __name__ == "__main__":
    n = int(input())
    if n < 3:
        print(-1)
        exit(0)
    res = (210 -(10**(n-1) % 210)) + 10**n;
    print(res)