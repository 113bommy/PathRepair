for i in range(int(input())):
    n=int(input())
    w=list(map(int,input().split()))
    ans=0
    w.sort()
    for z in range(2,2*n):
        fre=0
        i=0
        j=n-1
        while i<n and j>-1 and i<j:
            if w[i]+w[j]==z:
                fre+=1
                i+=1
                j-=1
            elif w[i]+w[j]<z:
                i+=1
            else:
                j-=1
        if fre>ans:
            ans=fre
    print(ans)