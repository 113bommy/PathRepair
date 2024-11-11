#input
n, k = map(int, input().split())

#output
mod = pow(10, 9) + 7

n_ = 2*10**5
fun = [1]*(n_+1)
for i in range(1,n_+1):
    fun[i] = fun[i-1]*i%mod
rev = [1]*(n_+1)
rev[n_] = pow(fun[n_],mod-2,mod)
for i in range(n_-1,0,-1):
    rev[i] = rev[i+1]*(i+1)%mod
def cmb(n,r):
    if n <= 0 or r < 0 or r > n: return 0
    return fun[n]*rev[r]%mod*rev[n-r]%mod

if n <= k-1:
    print(cmb(2*n-1, n))
else:
    answer = 0
    for m in range(k+1):
        answer += cmb(n, m)*cmb(n-1, m) % mod
        answer %= mod
    print(answer)