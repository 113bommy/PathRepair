import sys

def solve():
    n,k, = rv()
    a, = rl(1)
    res = 0
    count = [0] * 10
    for i in range(n):
        if a[i] < 100:
            count[10 - (a[i] % 10) - 1] += 1
            res += a[i] // 10
    for i in range(10):
        while count[i] > 0 and k >= i + 1:
            res += 1
            count[i] -= 1
            k -= i + 1
    already = res * 10
    possible = n * 100
    diff = possible - already
    if diff > 0:
        actual = min(diff, k)
        res += actual // 10
    print(res)






def prt(l): return print(' '.join(map(str, l)))
def rs(): return map(str, input().split())
def rv(): return map(int, input().split())
def rl(n): return [list(map(int, input().split())) for _ in range(n)]  
if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
solve()