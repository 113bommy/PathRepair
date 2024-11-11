n,m,q=map(int,input().split())
def gcd(x,y):
    if y:
        return gcd(y,x%y)
    return x
g=gcd(n,m)
x=n/g
y=m/g
for _ in range(q):
    a,b,c,d=map(int,input().split())
    i=(b-1)//(y if a>1 else x)
    j=(d-1)//(y if c>1 else x)
    print('YES' if i==j else 'NO')
