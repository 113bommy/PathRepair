import sys
import math
import bisect

def solve(A):
    upper = 20 * 10 ** 3
    pos = 20 * 10**3
    for p in A:
        if p[1] == 'North':
            pos += p[0]
        elif p[1] == 'South':
            pos -= p[0]
        elif p[1] == 'East':
            if abs(pos) == upper:
                return False
        elif p[1] == 'West':
            if abs(pos) == upper:
                return False
        if pos > upper or pos < -upper:
            return False
    return pos == upper

def main():
    A = []
    for _ in range(int(input())):
        s = input().split()
        A.append([int(s[0]), s[1]])
    if solve(A):
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    main()
