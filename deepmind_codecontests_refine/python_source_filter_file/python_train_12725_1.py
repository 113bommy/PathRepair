[n, m, L, R] = [int(s) for s in input().split()]
mod = 998244353
ret = pow(R-L+1, n*m, 2*mod)
if not n*m%2:
    ret = (ret+1) // 2
print(int(ret))
