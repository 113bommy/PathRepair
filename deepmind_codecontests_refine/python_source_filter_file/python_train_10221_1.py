def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

n,m,q=list(map(int,input().split()))
a=gcd(n,m)

for _ in range(q):
    a1,a2,a3,a4=list(map(int,input().split()))
    if a1==1:
        a1=n//a
    if a1==2:
        a1=m//a
    if a3==1:
        a3=n//a
    if a3==2:
        a3=m//a
    if (a2-1)//a1==(a4-1)//a3:
        print("YES")
    else:
        print("NO")
