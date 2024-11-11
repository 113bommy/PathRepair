import os
import sys

DEBUG = 'DEBUG' in os.environ


def inp():
    return sys.stdin.readline().rstrip()


def read_int():
    return int(inp())


def read_ints():
    return [int(e) for e in inp().split()]


def dprint(*value, sep=' ', end='\n'):
    if DEBUG:
        print(*value, sep=sep, end=end)

##########################################


def main():
    a, b, n, S = read_ints()
    a_max = S // n
    if a > a_max:
        b_needed = S-a_max*n
    else:
        b_needed = S-a*n
    if b > b_needed:
        return "YES"
    else:
        return "NO"


for _ in range(read_int()):
    print(main())
