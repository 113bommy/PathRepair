#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open('input.txt', 'r')
MOD = 998244353
sys.setrecursionlimit(1000000)

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
i, j = 0, 0
sa, sb, ans = 0, 0, 0
ta, tb = True, True
while i < n and j < m:
    if ta:
        sa += a[i]
    if tb:
        sb += b[j]
    if sa == sb:
        ans += 1
        i += 1
        j += 1
        sa, sb = 0, 0
        ta, tb = True, True
    elif sa < sb:
        i += 1
        ta, tb = True, False
    else:
        j += 1
        ta, tb = False, True
if sa != sb:
    ans = -1
print(ans)