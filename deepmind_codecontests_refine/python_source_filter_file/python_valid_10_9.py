for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    v=[[] for i in range(n+1)]
    for i in range(n):
        v[a[i]].append(i)

    res=[0 for i in range(n)]
    j=0
    for i in range(n+1):
        if len(v[i])>=k:
            for ind in range(k):
                res[v[i][ind]]=ind+1
        else:
            for x in v[i]:
#                 if k!=0:
                res[x]=(j%k)+1
                j+=1
#     print(res)
#     print(v)
    mp=[0 for i in range(k+1)]
    for i in range(n):
        if res[i]!=0:
            mp[res[i]]+=1
    #print(mp)     
    mn=10*9+7
    for i in range(1,k+1):
        mn=min(mn,mp[i])

    for i in range(n):
        if res[i]!=0:
            if mp[res[i]]>mn:
                mp[res[i]]-=1
                res[i]=0
    print(*res)
    #print(mp)