import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

mod = 10**9+7
n,k = na()
a = na()
a.sort()

ans = 1

if k == 1:
    print(a[-1])
    exit()

if a[-1] <= 0 and k%2==1:
    for i in range(n-k,n):
        ans = ans*a[i]%mod
    print(ans%mod)
    exit()

s = 0
e = -1

while k > 0:
    if k == 1:
        if a[s] > a[e]:
            ans = ans*a[s]%mod
        else:
            ans = ans*a[e]%mod
        break
    p = a[s]*a[s+1]
    q = a[e]*a[e-1]
    if p > q:
        ans = p%mod*ans%mod
        s+=2
    else:
        ans = q%mod*ans%mod
        e-=2
    k-=2

print(ans%mod)