for _ in range(int(input())):
    n,res,r = int(input()),{},-1
    a = list(map(int,input().split()))
    for i in range(len(a)):
        for j in range(len(a)):
            if i!=j:
                t = res.get(a[i]^a[j],0)
                res[a[i]^a[j]]=t+1
    for i in res.keys():
        if res[i]==len(a):
            if r==-1:r=i
            elif r>i:i=r
    print(r)
