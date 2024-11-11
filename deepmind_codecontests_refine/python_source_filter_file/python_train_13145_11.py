for i in range(int(input())):
    a=list(map(int,input().strip().split(" ")))
    b=list(map(int,input().strip().split(" ")))
    b.append(b[0])
    b.insert(0,b[-2])
    
    for j in range(1,len(b)-1):
        b[j]=min(b[j-1]+b[j+1],b[j])
    s=0
    if a[1]>0 and a[0]>0:
        s+=min(a[1],a[0])*b[1]
        c=min(a[1],a[0])
        a[1]-=c
        a[0]-=c
    elif a[1]<0 and a[0]<0:
        s-=max(a[1],a[0])*b[4]
        c=max(a[1],a[0])
        a[1]+=c
        a[0]+=c
    if a[0]>0:
        s+=a[0]*b[6]
    if a[0]<0:
        s+=-a[0]*b[3]
    if a[1]>0:
        s+=a[1]*b[2]
    if a[1]<0:
        s+=-a[1]*b[5]
    print(s)