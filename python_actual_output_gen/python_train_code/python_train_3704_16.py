l,r,a=list(map(int,input().split()))
if a==0 and l==0:
    print(0)
elif a==0 and r==0:
    print(0)
elif (l+r+a)%2==0 and l==r:
    print(l+r+a)
elif l==r:
    print((l+a//2)*2)
elif l<r:
    if r-l<=a:
        t=r*2
        if (a-(r-l))>1:
            t+=((a-(l-r))//2)*2
            print(t)
        else:
            print(t)
    elif r-l>a:
        print((l+a)*2)
else:
    if l-r<=a:
        t=2*l
        if (a-(l-r))>1:
            t+=((a-(l-r))//2)*2
            print(t)
        else:
            print(t)
    elif l-r>a:
        print((r+a)*2)
        
        
    
