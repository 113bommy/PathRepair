from sys import stdin, stdout
import collections
import heapq
import itertools
import functools
import math
import operator
import string

ALPHABET = string.ascii_lowercase
DIGITS = string.digits

def read_line():
    return stdin.readline().strip()
def read_int():
    return int(read_line())
def read_arr():
    return read_line().split(' ')
def read_int_arr():
    return [int(x) for x in read_arr()]
def query_interactive(s):
    print(s)
    stdout.flush()

def solve():
    l, r = read_int_arr()

    if r >= 2 * l:
        print("NO")
    else:
        print("YES")


def main():
    T = 1
    T = read_int()
    for _ in range(T):
        solve()

if __name__ == "__main__":
    main()
