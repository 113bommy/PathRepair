def min_price(n,k,l,m):
    s=sum(m)
    for i in range(n):
        l[i]-=m[i]
    l.sort()
    for i in range(n):
        if i<k or l[i]<0:
            s+=l[i]
        else:
            break
    return sum(m)+s

n,k=map(int,input().split())
l=list(map(int,input().split()))
m=list(map(int,input().split()))
print(min_price(n,k,l,m))