from math import gcd

n=int(input())
a=list(map(int,input().split()))
m=a.count(1)
if m>0:
    print(n-m)
    exit()
ans=-1
for i in range(n):
    d=a[i]
    c=i
    for j in range(i+1,n):
        d=gcd(d,a[j])
        if d==1:
            c=j
            break
    if c>i:
        if ans<0:
            ans=c-i+n
        else:
            ans=min(ans,c-i+n)
print(ans)