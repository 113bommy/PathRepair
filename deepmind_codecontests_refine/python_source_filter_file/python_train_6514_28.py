import sys
import math
import bisect

def solve(a, b):
    if a == 0 or b == 0:
        return False
    return abs(a - b) <= 1

def main():
    a, b = map(int, input().split())
    if solve(a, b):
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    main()
