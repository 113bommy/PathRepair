def pgcd(a,b):
    if a==0 or b==0:
        return a+b
    return pgcd(b,a%b)

def ppcm(a,b):
    return a*b//pgcd(a,b)
        
n,a,b,p,q=map(int, input().split())

N=0

if a<n or b<n:
    N=p*(n//a)+q*(n//b)-min(p,q)*(n//ppcm(a,b))

print(N)