import sys

def solve():
    n, m = map(int, input().split())
    res = 0
    tab = [list(input()) for _ in range(n)]
    for row in range(n):
        for col in range(m):
            tab[row][col] = 1 if tab[row][col] == 'W' else -1
    for row in range(n - 1, -1, -1):
        for col in range(m - 1, -1, -1):
            if tab[row][col] != 0:
                diff = tab[row][col]
                res+=1
                for i in range(row + 1):
                    for j in range(col + 1):
                        tab[i][j] -= diff
    return res
if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
print(solve())