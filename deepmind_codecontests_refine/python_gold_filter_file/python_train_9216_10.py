import sys
input= lambda:sys.stdin.readline()
MOD = 1000000007
ii = lambda: int(input())
si = lambda: input()
dgl = lambda: list(map(int, input()))
f = lambda: list(map(int, input().split()))
il = lambda: list(map(int, input().split()))
ls = lambda: list(input())
n, a, b, c, d = f()
mx = max(a+b, b+d, c+d, a+c)
mn = min(a+b, b+d, c+d, a+c)
print(max(0,n*n-(mx-mn)*n))