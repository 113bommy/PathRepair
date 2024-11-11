# Author Name: Ajay Meena
# Codeforce : https://codeforces.com/profile/majay1638
import sys
import math
import bisect
import heapq
from bisect import bisect_right
from sys import stdin, stdout

# -------------- INPUT FUNCTIONS ------------------


def get_ints_in_variables(): return map(
    int, sys.stdin.readline().strip().split())


def get_int(): return int(sys.stdin.readline())


def get_ints_in_list(): return list(
    map(int, sys.stdin.readline().strip().split()))
def get_list_of_list(n): return [list(
    map(int, sys.stdin.readline().strip().split())) for _ in range(n)]


def get_string(): return sys.stdin.readline().strip()

# -------- SOME CUSTOMIZED FUNCTIONS-----------


def myceil(x, y): return (x + y - 1) // y

# -------------- SOLUTION FUNCTION ------------------


def clearGridCol(grid):
    for i in range(4):
        sm = 0
        for j in range(4):
            sm += grid[j][i]
        if sm == 4:
            for j in range(4):
                grid[j][i] = 0


def clearGridRow(grid):
    for i in range(4):
        sm = 0
        for j in range(4):
            sm += grid[i][j]
        if sm == 4:
            for j in range(4):
                grid[i][j] = 0


def Solution():
    # Write Your Code Here
    s = get_string()
    cnt0 = 0
    cnt1 = 0
    for c in s:
        if c == "0":
            if cnt0 == 0:
                print(1, 1)
                cnt0 += 1
            elif cnt0 == 1:
                print(3, 1)
                cnt0 += 1
            if cnt0 == 2:
                cnt0 = 0
        else:
            if cnt1 == 0:
                print(4, 3)
                cnt1 += 1
            elif cnt1 == 1:
                print(4, 1)
                cnt1 += 1
            if cnt1 == 2:
                cnt1 = 0


def main():
    # Take input Here and Call solution function
    Solution()


# calling main Function
if __name__ == '__main__':
    main()
