t=int(input())

for _ in range(t):
    N,W=map(int,input().split())

    weight=list(map(int,input().split()))

    ID=list(range(1,N+1))
    c=zip(weight,ID)

    cc=sorted(c,reverse=True)

    ans=[]
    A=0
    isOK=False

    for i in range(N):
        if cc[i][0]>W:
            continue
        else:
            A+=cc[i][0]
            ans.append(cc[i][1])
        
        if 0<A and W//2<=A and A<=W:
            isOK=True
            break
        
    if isOK:
        print(len(ans))
        print(*ans)
    else:
        print(-1)



