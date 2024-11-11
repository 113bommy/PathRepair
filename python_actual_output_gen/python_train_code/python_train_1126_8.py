def poisk(x,l,r):
    if l>=r-1:
        return r
    y=(l+r)//2
    if y*(y-1)//2>=x:
        r=y
    else:
        l=y
    return poisk(x,l,r)    
n,m=map(int,input().split())
min1=n-m*2
if min1<0:
    min1=0
max1=n-poisk(m,0,10**6)
print(min1,max1)
