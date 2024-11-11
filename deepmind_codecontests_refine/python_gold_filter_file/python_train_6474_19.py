n,m = map(int, input().split())
mo = 10**9 + 7
res = pow(2, m, mo)
res %= mo
res -= 1
res = pow(res, n, mo)
res %= mo
print(res)