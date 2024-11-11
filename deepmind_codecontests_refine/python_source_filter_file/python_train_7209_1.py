for _ in range(int(input())):
    if _: input()
    n,m = map(int,input().split())
    a1 = sorted( (tuple(map(int,input().split())) for i in range(m)),reverse=True)
    a2 = sorted(a1,key=lambda x: x[1],reverse=True)
    a1.append((0,0)) ; r=0;s=0;ans=0
    for x, y in a2 :
        while r < m and a1[r][0] > y :
            s+= a1[r][0] ; r+= 1
        if x> y and a1[r][0] < x :
            cs = s + (n-r)*y 
        else :
            cs = s+x+(n-r-1)*y 
        ans = max(cs,ans)
    print(ans,flush=False)            
                