r1,c1,r2,c2 = map(int,input().split())
mod = 10**9+7

def p_mod(m,n,p):
    a = 1
    for i in range(n):
        a = a*(m-i) % p
    return a

def c_mod(m,n,p):
    return (p_mod(m,n,p)*pow(p_mod(n,n,p),p-2,p)) % p

print((c_mod(r2+c2+2,r2+1,mod) - c_mod(r1+c2+1,r1,mod) - c_mod(r2+c1+1,c1,mod) + c_mod(r1+c1,r1,mod)) % mod)