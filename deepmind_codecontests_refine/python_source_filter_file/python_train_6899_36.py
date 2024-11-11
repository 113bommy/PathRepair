import sys
import math
from collections import defaultdict,deque

input = sys.stdin.readline
def inar():
    return [int(el) for el in input().split()]
def main():
    s=input().strip()
    n=len(s)
    print(3)
    print("R",n-1)
    print("L",n)
    print("R",2)


if __name__ == '__main__':
    main()



