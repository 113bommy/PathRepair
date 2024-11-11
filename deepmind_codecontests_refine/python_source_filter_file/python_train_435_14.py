#!/usr/bin/env python3
import sys

#lines = stdin.readlines()
def rint():
    return map(int, sys.stdin.readline().split())

def input():
    return sys.stdin.readline().rstrip('\n')

def oint():
    return int(input())


t = oint()

for _ in range(t):
    ss = input()
    s, c = ss.split()
    #print(s)
    #print(c)
    s = list(s)
    c = list(c)
    ls = len(s)
    lc = len(c)
    l = min(ls, lc)
    find = 0
    for i in range(l):
        if ord(s[i]) == ord(c[i]):
            for j in range(i+1, l):
                if ord(s[j]) < ord(s[i]):
                    s[i], s[j] = s[j], s[i]
                    find = 1
                    break
        elif ord(s[i]) > ord(c[i]):
            for j in range(i+1, l):
                if ord(s[j]) < ord(c[i]):
                    s[i], s[j] = s[j], s[i]
                    find = 1
                    break
            else:
                for j in range(l-1, i, -1):
                    if ord(s[j]) == ord(c[i]):
                        s[i], s[j] = s[j], s[i]
                        break
                else:
                    find = -1
                    break
                for j in range(i+1, l):
                    if ord(s[j]) < ord(c[j]):
                        find = 1
                        break
                    elif ord(s[j]) > ord(c[j]):
                        find = -1
                        break
                if find:
                    break
                if ls < lc:
                    find = 1
                    break
                else:
                    find = -1
                    break
        else:
            find = 1
            break
        if find:
            break
    if find == 0:
        if ls < lc:
            find = 1
        else:
            find = -1

    if find == 1:
        print("".join(s))
    else:
        print("---")

