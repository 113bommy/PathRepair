from fractions import gcd

def solve(p, q, a, n, l=1):
    ans = 1 if p==1 and q<=a and q>=l else 0
    denom = max(l, q//p)
    p_denom = denom*p
    while n*q >= p_denom and denom <= a:  #n/denom >= p/q:
        p_, q_ = p_denom-q, q*denom
        if p_ <= 0:
            denom += 1
            p_denom += p
            continue
        gcd_ = gcd(p_, q_)
        p_ //= gcd_
        q_ //= gcd_
        if n==2 and p_==1 and q_*denom<=a and q_>=denom:
            ans += 1
        else:
            ans += solve(p_, q_, a//denom, n-1, denom)
        denom += 1
        p_denom += p
    #print(p, q, a, n, l, ans)
    return ans

while True:
    p, q, a, n = map(int, input().split())
    if p==q==a==n==0:
        break
    gcd_ = gcd(p, q)
    p //= gcd_
    q //= gcd_
    if n==1:
        print(1 if p==1 and q<=a else 0)
    else:
        print(solve(p, q, a, n))

