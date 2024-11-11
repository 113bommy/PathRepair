n,m=map(int,input().split())
s=input()
t=input()

def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)

G=gcd(n,m)
a,b = n//G,m//G
s=s[1::a]
t=t[1::b]
if s==t: print(a*b*G)
else: print(-1)