for _ in range(int(input())):
    n,k = map(int,input().split())
    x = list(map(int,input().split()))
    y = list(map(int,input().split()))
    x.sort()
    l,r = [0]*n,[0]*n

    j=n-1
    for i in range(n-1,0,-1):
        while x[j]-x[i]>k: j-=1
        r[i] = j-i+1
        if i+1<n: r[i] = max(r[i],r[i+1])

    j=0
    for i in range(1,n):
        while x[i]-x[j]>k: j+=1
        l[i] = i-j+1
        if i>0: l[i] = max(l[i],l[i-1])

    ans = 1
    for i in range(n-1):
        ans = max(ans,l[i]+r[i+1])
    print(ans)


    
    



    
    

            
        

    





    


    