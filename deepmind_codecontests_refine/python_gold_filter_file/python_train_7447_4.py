def vafp(l,h,k):
    c=0
    s=0
    for i in range(len(l)):
        if(l[i]+s<=h):
            p=l[i]+s
            if(p>=k):
                c=c+(p//k)
                s=(p%k)
            else:
                s=s+l[i]
        else:
            c=c+1
            c=c+(l[i]//k)
            s=(l[i]%k)
            
    if(s>0):
        c=c+1
    print(c)
    return
        

        
n,h,k=map(int,input().split())
l=list(map(int,input().split()))
vafp(l,h,k)