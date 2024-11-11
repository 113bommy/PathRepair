def com(n,r,mod):
    k=min(r,n-r)
    C=1
    for i in range(1,k+1):
        C=(C*(n+1-i)*pow(i,mod-2,mod))%mod
    return C

x, y = map(int,input().split())
mod = 10 ** 9 + 7

m = 2 * x - y
n = 2 * y - x
if m > 0 and n > 0 and m % 3 == 0 and n % 3 == 0:
    print(com((n + m) // 3, n // 3, mod))
else:print(0)