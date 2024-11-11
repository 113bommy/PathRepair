
base = 123
mod = 10**9+7
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
base_m = pow(base, N-1, mod)
ans = [True]*N
for k in range(30):
    tmp = []
    mask = 1<<k
    a_k = []
    a_k_r = []
    b_k = []
    for i in range(N):
        if a[i]&mask:
            a_k.append(1)
            a_k_r.append(0)
        else:
            a_k.append(0)
            a_k_r.append(1)
        if b[i]&mask:
            b_k.append(1)
        else:
            b_k.append(0)
    b_hash = b_k[0]
    a_hash = a_k[0]
    a_hash_r = a_k_r[0]
    for i in range(1, N):
        b_hash = (b_hash*base+b_k[i])%mod
        a_hash = (a_hash*base+a_k[i])%mod
        a_hash_r = (a_hash_r*base+a_k_r[i])%mod
    for i in range(N):
        if a_hash == b_hash or a_hash_r == b_hash:
            pass
        else:
            ans[i] = False
        a_hash = ((a_hash-a_k[i]*base_m)*base+a_k[i])%mod
        a_hash_r = ((a_hash_r-a_k_r[i]*base_m)*base+a_k_r[i])%mod
for i in range(N):
    if ans[i]:
        x = a[i]^b[0]
        print(i, x)



    
