n, a, b = map(int, input().split())
m = 10**9+7
def cmb(r):
    N = 1
    R = 1
    for i in range(r):
        N = N*(n - i) % m
        R = R*(i+1) % m
    return N*pow(R, m-2, m)%m

ans = pow(2, n, m) - ((cmb(a) + cmb(b) + 1)%m)
print(ans)