import sys, math
from fractions import gcd
from itertools import permutations

debug = 0
if debug:
    f = open("input.txt", "r")
    input = f.readline
else:
    input = sys.stdin.readline

def mp():
    # global input
    return list(map(int, input().strip().split()))

def _main():
    n, k = mp()
    a = list(input().strip())
    a.sort()
    ans = []
    for i in range(n):
        if len(ans) == 0 or abs(ord(a[i]) - ord(ans[-1])) > 1:

            ans += [a[i]]

    if len(ans) < k:
        print(-1)
        return
    sum = 0
    #print(a, ans)
    for i in range(k):
        sum += ord(ans[i]) - ord("a") + 1
    print(sum)


_main()
