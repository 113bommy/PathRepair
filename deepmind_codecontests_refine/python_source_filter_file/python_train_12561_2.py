def well_played():
    n,a,b = [int(x) for x in input().split()]
    p = [(0,0)] * n
    b= min(b,n)

    for i in range(n):
        h,d =[int(x) for x in input().split()]
        p[i] =(h,d)
    p.sort(key=lambda x:x[0]-x[1],reverse=True)
    
    s=0
    for i in range(b):
        s+=max(p[i][0],p[i][1])
    for i in range(b,n):
        s+= p[i][1]
    
    ans = s
    for i in range(b):
        ans = max(ans,s - max(p[i][0],p[i][1]) + ((p[i][0]) <<a)  )
    s-= max(p[b-1][0],p[b-1][1]) + p[b-1][1]
    if(b):
        for i in range(b,n):
            ans= max(ans,s - p[i][1] + ((p[i][0]) <<a) )
    print(ans)
well_played() 