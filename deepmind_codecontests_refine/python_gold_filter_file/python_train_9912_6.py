for u in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    f=0
    s=0
    for i in range(n):
        s=s+l[i]
        if(s>k):
            f=i+1
            break
    if(f==0):
        print(0)
    else:
        m=max(l[:f])
        if(l[f-1]<m):
            print(l.index(m)+1)
        else:
            print(f)
