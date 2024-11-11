# -*- coding: utf-8 -*-
"""
Created on Thu Jun 21 14:44:39 2018

@author: Arsanuos
"""
import math

def div(n):
    s = int(math.sqrt(n)) + 1
    arr = []
    for i in range(1, s):
        if n%i == 0:
            if n/i == i:
                arr.append(i)
            else:
                arr.append(i)
                arr.append(int(n/i))
    arr.sort(reverse=False)
    return arr


def main():
    #rd = lambda : list(map(int, input().split()))
    n = int(input())
    t = input()
    arr = div(n)
    for d in arr:
        t = "".join(reversed(t[:d])) + t[d:]
    print(t)
if __name__ == "__main__":
    main()