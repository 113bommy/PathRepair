#!/usr/bin/env python3
from sys import stdin


def solve(tc):
    s = stdin.readline().strip()
    prev_vowel = False
    vowel = False
    for i in range(1,len(s)):
        prev_vowel = False
        vowel = False
        if s[i-1] in ['a','e','i','o','u','n']:
            prev_vowel = True

        if s[i] in ['a','e','i','o','u','n']:
            vowel = True
        
        if not prev_vowel and not vowel:
            print("NO")
            return

    vowel = False
    if s[-1] in ['a','e','i','o','u','n']:
        vowel = True

    if not vowel:
        print("NO")
    else:
        print("YES")
    return


LOCAL_TEST = not __debug__
if LOCAL_TEST:
    infile = __file__.split('.')[0] + "-test.in"
    stdin = open(infile, 'r')

tcs = (int(stdin.readline().strip()) if LOCAL_TEST else 1)
tc = 1
while tc <= tcs:
    solve(tc)
    tc += 1