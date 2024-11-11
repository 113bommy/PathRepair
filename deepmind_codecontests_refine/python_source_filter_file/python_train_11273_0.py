

def ncr(n, r, p):
    # initialize numerator
    # and denominator
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, 
            p - 2, p)) % p
            
def solve(n,a):
    a.sort()
    M = 998244353
    ss = sum(a[:n]) 
    ls = sum(a[n:])
    diff = (ls-ss)%M
    return diff * ncr(2*n,n,M)
n = int(input())
a = list(map(int,input().split()))
print(solve(n,a))