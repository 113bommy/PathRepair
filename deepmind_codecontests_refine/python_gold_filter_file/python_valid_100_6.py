from collections import Counter

def il(): #Input list
    return list(map(int,input().split()))
def ii(): #Input int
    return int(input())
def imi(): #Input multiple int
    return map(int,input().split())

p=998244353
fac=[1]*200007
for i in range(2,200007):
    fac[i]=(fac[i-1]*i)%p


t=ii()
for _ in range(t):
    n=ii()
    ar=il()
    co=Counter(ar)

    m1=max(ar)
    if co[m1]>1:
        print(fac[n])
        continue

    m2=0
    for i in ar:
        if i!=m1: m2=max(m2,i)
    if (m1-m2)>1: print(0)
    else:
        y = co[m2]
        m=n-y-1
        a=1
        for b in range(n-m+1,n+1): a=(a*b)%p
        a=(a*fac[y])%p
        print((p+fac[n]-a)%p)










