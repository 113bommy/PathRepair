import sys
def fastio():
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    input = lambda : sys.stdin.readline().rstrip('\r\n')
    sys.stdout = StringIO()
    register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

def debug(*var, sep = ' ', end = '\n'):
    print(*var, file=sys.stderr, end = end, sep = sep)

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

n, = I()
cost = I()
ans = 0
previous = ''
dp = [[INF] * 2 for i in range(n + 1)]
dp[0] = [0, 0]
for i in range(n):
    s = input()
    if s >= previous:
        dp[i + 1][0] = dp[i][0]
    if s >= previous[::-1]:
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1])
    s = s[::-1]
    if s >= previous:
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + cost[i])
    if s >= previous[::-1]:
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + cost[i])
    previous = s[::-1]
if dp[n][0] >= INF and dp[n][1] >= INF:
    print(-1)
    exit()
print(min(dp[n]))