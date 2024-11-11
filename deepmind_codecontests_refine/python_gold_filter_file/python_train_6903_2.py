for _ in range(int(input())):
    n,p=map(int,input().split())
    arr=list(map(int,input().split()))
    l=[]
    for i in range(n):
        l.append([arr[i],i])
    l.sort()
    vis=set()
    ans=0
    for i in l:

        ele=i[0]
        ind=i[1]
        if ele>p :
            break
        if ind in vis:
            continue
        while(ind>0):
            if ind-1 in vis:
                break
            if arr[ind-1]%ele==0:
                vis.add(ind-1)
                ans+=ele
            else:
                break
            ind-=1
        ind = i[1]
        while (ind < n-1):

            if ind in vis:
                break
            if arr[ind + 1] % ele == 0:
                vis.add(ind)
                ans += ele
            else:
                break
            ind += 1
    for i in range(n-1):
        if i not in vis:
            ans+=p
    print(ans)

