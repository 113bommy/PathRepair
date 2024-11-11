from fractions import gcd

n=int(input())
a=list(map(int,input().split()))

l=[0]*(n)
for i in range(n-1):
    l[i+1] = gcd(l[i],a[i])

r=[0]*(n)
for i in range(n-2,-1,-1):
    r[i] = gcd(r[i+1],a[i+1])

print(max([gcd(r[i],l[i]) for i in range(n)]))

