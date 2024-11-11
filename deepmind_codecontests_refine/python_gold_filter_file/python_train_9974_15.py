import fractions

ans=1
n=int(input())
a=list(map(int,input().split()))
l=[0]
r=[0]
for i in range(n-1):
    l.append(fractions.gcd(l[i],a[i]))
    r.append(fractions.gcd(r[i],a[-(i+1)]))
for i in range(n):
    c=fractions.gcd(l[i],r[-(i+1)])
    if ans<c:
        ans=c
print(ans)