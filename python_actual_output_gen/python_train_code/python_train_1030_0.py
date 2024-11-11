import sys

def solve():
    a = list(map(int, list(input())))
    res = 1
    curcount = 1
    for i in range(1, len(a)):
        if a[i] + a[i-1] == 9:
            curcount += 1
        else:
            if curcount > 2 and curcount % 2 == 1:
                res*=(curcount//2 + 1)
            curcount = 1
    if curcount > 2 and curcount % 2 == 1:
        res*= curcount
    return res



if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
print(solve())