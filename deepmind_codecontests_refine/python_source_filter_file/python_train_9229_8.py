#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import sys

def print_list(l):
    for e in l:
        print(*e)
    return

def main():
    n,k = map(int,sys.stdin.readline().strip().split())
    grid = [['.' for _ in range(n)] for _ in range(4)]

    q = k//2
    r = k %2

    if r == 0:
        for i in range(q):
            grid[1][i+1] = "#"
            grid[2][i+1] = "#"
        print("YES")
        print_list(grid)
    else:
        for i in range(q):
            grid[1][i+1] = "#"
            grid[1][n-(i+2)] = "#"
        if k > n-2:
            reste = k-(n-2)
            for i in range(reste//2):
                grid[2][i+1] = "#"
                grid[2][n-(i+2)] = "#"
        else:
            grid[2][n//2] = '#'

        print("YES")
        print_list(grid)


main()
