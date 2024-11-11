import sys

def f1(m):
    j=0
    num=0
    for x in ap:
        while j<minus and x*am[j]<m:
            j+=1
        num+=j
    return plus*minus-num
            
def f2(m):
    return f3(m,ap)+f3(m,am)


def f3(m,l):
    nagasa=len(l)
    if nagasa<2: return 0
    j=nagasa-1
    num=0
    for i in range(nagasa):
        while j>-1 and l[i]*l[j]>m:
            j-=1
        num+=j+1
        if i<=j: num-=1
    return num//2

n,k=map(int,input().split())
a=list(map(int,input().split()))
ap=sorted([a[i] for i in range(n) if a[i]>0])
am=sorted([-a[i] for i in range(n) if a[i]<0])
az=sorted([a[i] for i in range(n) if a[i]==0])

plus,minus,zero=len(ap),len(am),len(az)
pz=plus*minus+zero*(zero-1)//2+zero*(n-zero)


if plus*minus>=k:
    h,l=0,10**18
    while l-h>1:
        md=(h+l)//2
        p=f1(md)
        if p>=k: h=md
        else: l=md
    print(-h-1)

elif pz>=k:
    print(0)

else:
    k-=pz
    h,l=10**20,0
    while h-l>1:
        md=(h+l)//2
        p=f2(md)
        if p>=k: h=md
        else: l=md
    print(h)