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

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

n, k = I()
s = input()
s = sorted(s)

def get(x):
    return ord(x) - 97 + 1
ans = get(s[0])
previous = get(s[0])
if k == 1:
    print(ans)
    exit()
count = 1
for i in range(1, n):
    if get(s[i]) - previous >= 2:
        previous = get(s[i])
        ans += previous
        count += 1
    if count == k:
        print(ans)
        break
else:
    print(-1)