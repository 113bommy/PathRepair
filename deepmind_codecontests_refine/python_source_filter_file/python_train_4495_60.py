#!pypy3

from sys import stdin

def readInts(): return map(int,stdin.readline().strip().split())

def solve(s):
    s2 = []
    vowels = "aeiouyAEIOUY"
    for c in s:
        if c in vowels: continue
        c2 = c.lower()
        s2.append(".")
        s2.append(c2)
    return "".join(s2)

def run():
    s = stdin.readline()
    print(solve(s))

run()
