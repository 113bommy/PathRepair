def calc(val,lista):
    mx=0
    for i in range(1,len(lista)):
        x,y=lista[i],lista[i-1]
        if x==-1:
            x=val
        if y==-1:
            y=val
        mx=max(mx,abs(x-y))
    return(mx)
for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    l,ret,h,m=0,0,10000000000,10000000000
    while l<h:
        mid=(l+(h-1))//2
        mx1=calc(mid,a)
        mx2=calc(mid+1,a)
        if mx1<mx2:
            h=mid
        else:
            m=mx2
            ret=mid+1
            l=mid+1
    if m==10000000000:
        m=0
    print(m,ret)
