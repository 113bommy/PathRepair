def gcd(a, b):
    if(a==0): return b
    return gcd(b%a, a)
    
def lcp(a, b):
    return a*b//gcd(a,b)

n, a, b, p, q = map(int,input().split())
print(n//a*p+n//b*q-n//lcp(a,b)*min(p,q))