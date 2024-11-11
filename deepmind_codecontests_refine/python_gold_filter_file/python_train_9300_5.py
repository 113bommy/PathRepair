import sys
import math

TESTING = False


def solve():
    n, = read()
    if n == 0: return 1
    MOD = 1000000007
    return (pow(2, n-1, MOD) + pow(2, 2*n-1, MOD)) % MOD

def read(mode=2):
    inputs = input().strip()
    if mode == 0: return inputs  # String
    if mode == 1: return inputs.split()  # List of strings
    if mode == 2: return list(map(int, inputs.split()))  # List of integers


def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    print(s, end="")


def run():
    if TESTING: sys.stdin = open("test.txt")
    res = solve()
    write(res)


run()