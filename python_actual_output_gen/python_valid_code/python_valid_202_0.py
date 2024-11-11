n, m, l, r = [int(i) for i in input().split()]
mod = 998244353
ans = 0
if (n*m)&1:
    ans = pow(r-l+1, m*n, mod)
else:
    if l&1 != r&1:
        k = 0
    elif l&1:
        k = 1
    else:
        k = -1
    ans = ((pow(r-l+1, m*n, mod) + k) * pow(2, mod-2, mod))%mod
print(ans)
    