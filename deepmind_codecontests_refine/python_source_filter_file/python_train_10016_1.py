t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    a=[int(x) for x in input().split()]
    b=[int(x) for x in input().split()]

    pos=[0]*(n+1)
    for i in range(0,len(a)):
        pos[a[i]]=i


    ptr=0
    ans=0
    for i in range(0,len(b)):
        if(pos[b[i]]>ptr):
            ans+=2*(pos[b[i]]-i)+1
            ptr=pos[b[i]]
        else:
            ans+=1
            ptr+=1

    print(ans)
