n , k = map(int, input().split())
l = list(map(int , input().split()))
if sum(l)>=k:
    l = [i for i in range(1,n+1)]
    print(n)
    print(*l)
else:
    temp = l.copy()
    temp.sort()
    test = []
    ans=[]
    i=0
    while sum(test)<k and i<len(l):
        x = l.index(temp[i])
        test.append(temp[i])
        if sum(test)<=k:
            ans.append(x+1)
        l[x]=0
        i=i+1
    print(len(ans))
    if len(ans)!=0:
        print(* ans)
