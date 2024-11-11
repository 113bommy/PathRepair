import sys
input = lambda: sys.stdin.readline().rstrip()
import bisect
import itertools
from collections import deque
from collections import Counter
def solve():
    n = int(input())
    ab = [list(map(int,input().split())) for _ in range(n)]
    a = Counter()
    b = Counter()
    for i in range(n):
        a[ab[i][0]] += 1
        b[ab[i][1]] += 1
    ans = n * (n - 1) * (n - 2) // 6
    for i in range(n):
        ans -= (a[ab[i][0]] - 1) * (b[ab[i][1] - 1])
    print(ans)
        








    
t = int(input())
for _ in range(t):
    solve()

