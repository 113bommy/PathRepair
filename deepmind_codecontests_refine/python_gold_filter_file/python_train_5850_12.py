t=int(input())
for i in range(t):
    c,m,x=[int(x) for x in input().split()]
    counter=m+c+x
    l=0
    r=10**9
    while r-l>1:
        mid=(l+r)//2
        if mid<=c and mid<=m and mid*3<=counter:
            l=mid
        else:
            r=mid
    print(l)
