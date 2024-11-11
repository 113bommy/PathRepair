#!/usr/bin/python3

def readln(): return list(map(int, input().split()))
import sys
def exit():
    print(-1)
    sys.exit()

n, m = readln()
mon = [list(input()) for _ in range(n)]
hor = [i for i in range(n) if mon[i] != ['.'] * m]
rmon = list(zip(*mon))
ver = [j for j in range(m) if rmon[j] != ('.',) * n]
mini = hor[0]
maxi = hor[-1]
minj = ver[0]
maxj = ver[-1]
cnt_in = len([1 for i in range(mini + 1, maxi) for j in range(minj + 1, maxj) if mon[i][j] == 'w'])
cnt_l = len([1 for i in range(mini + 1, maxi) if mon[i][minj] == 'w'])
cnt_r = len([1 for i in range(mini + 1, maxi) if mon[i][maxj] == 'w'])
cnt_d = len([1 for j in range(minj + 1, maxj) if mon[mini][j] == 'w'])
cnt_u = len([1 for j in range(minj + 1, maxj) if mon[maxi][j] == 'w'])
if cnt_in:
    exit()
if maxi - mini < maxj - minj:
    k = maxj - minj + 1
    if maxi == mini and cnt_d:
        if mini >= k - 1:
            mini -= k - 1
        elif maxi + k - 1 < n:
            maxi += k - 1
        else:
            exit()
    else:
        if not cnt_d:
            mini = max(0, maxi - k + 1)
        if maxi - maxi + 1 != k and not cnt_u:
            maxi = min(mini + k - 1, n - 1)
        if maxi - mini + 1 != k:
            exit()
else:
    k = maxi - mini + 1
    if maxj == minj and cnt_l:
        if minj >= k - 1:
            minj -= k - 1
        elif maxj + k - 1 < m:
            maxj += k - 1
        else:
            exit()
    else:
        if not cnt_l:
            minj = max(0, maxj - k + 1)
        if maxj - minj + 1 != k and not cnt_r:
            maxj = min(minj + k - 1, m - 1)
        if maxj - minj + 1 != k:
            exit()
for i in range(mini, maxi + 1):
    if mon[i][minj] == '.':
        mon[i][minj] = '+'
for i in range(mini, maxi + 1):
    if mon[i][maxj] == '.':
        mon[i][maxj] = '+'
for j in range(minj, maxj + 1):
    if mon[mini][j] == '.':
        mon[mini][j] = '+'
for j in range(minj, maxj + 1):
    if mon[maxi][j] == '.':
        mon[maxi][j] = '+'
print('\n'.join([''.join(row) for row in mon]))
