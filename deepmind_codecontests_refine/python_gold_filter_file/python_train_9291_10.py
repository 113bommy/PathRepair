# import sys
# sys.setrecursionlimit(100000)

# f = open('input.txt')
# a = list(map(int, f.readline().split()))
# f.close()
# f = open('output.txt', 'w+')
# f.close()

inp = lambda: int(input())
inpm = lambda: map(int, input().split())
inpl = lambda: list(inpm())
l2mn = lambda _n, _m: [[0 for __ in range(_m)] for _ in range(_n)]
l2n = lambda _n: l2mn(_n, _n)
INF = int(1e18)
MOD = int(1e9) + 7  # 998244353
N = 2000009
"""

"""
def pr(a):
    for s in a:
        print(*s, sep="")
def ss(a):
    s = 0
    for e in a:
        s += sum(e)
    return s
A = [[1, 1, 1],
     [1, 1, 1],
     [1, 0, 1]]
def solve():
    n, k = inpm()

    if n == 3 and k == 8:
        print(2)
        pr(A)
        return

    kk = k % n
    res = 0 if kk == 0 else 2
    a = [[0 for j in range(n)] for i in range(n)]
    if k == 0:
        print(res)
        pr(a)
        return
    b = False
    for q in range(0, n, 2):
        for i in range(n - q):
            a[i + q][i] = 1
            k -= 1
            if k == 0:
                b = True
                break
        if b:
            break
        for i in range(q):
            a[i][n - q + i] = 1
            k -= 1
            if k == 0:
                b = True
                break
        if b:
            break

    if k == 0:
        print(res)
        pr(a)
        return

    for q in range(1, n, 2):
        for i in range(n - q):
            a[i + q][i] = 1
            k -= 1
            if k == 0:
                b = True
                break
        if b:
            break
        for i in range(q):
            a[i][n - q + i] = 1
            k -= 1
            if k == 0:
                b = True
                break
        if b:
            break
    print(res)
    pr(a)
    # print(ss(a))
    # print(b)

'''
1
4 7

1
4 9

'''

def main():
    t = inp()  # 1  #
    for i in range(t):
        solve()
        # print()
main()
