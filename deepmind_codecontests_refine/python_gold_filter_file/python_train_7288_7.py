def countingsort(a,k):
    c=[0]*(k+1)
    n=len(a)
    for i in a:
        c[i]+=1
    for i in range(1,k+1):
        c[i]=c[i]+c[i-1]
    b=[0]*n
    for i in range(n-1,-1,-1):
        b[c[a[i]]-1]=a[i]
        c[a[i]]-=1
    return b
o=int(input())
a=list(map(int,input().split()))
q=max(a)
ret=countingsort(a,q)
for i in range(o):
    if i!=o-1:
        print(ret[i],end=" ")
    else:
        print(ret[i])
