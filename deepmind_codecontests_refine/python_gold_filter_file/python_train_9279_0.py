n,x,y =map(int,input().split())

xx = int(x**.5)
if x>=y :
    
    if xx*xx + (n-1)>=x  and xx + n-1<=y :
        print(xx)
        for i in range(n-1):
            print(1)
    elif (xx*xx)*2 + (n-2)>=x and 2*xx +n-2<=y :
        print(xx)
        print(xx)
        for i in range(n-2):
            print(1)
    elif (xx+1)*(xx+1) + (n-1)>=x and (xx+1) +n-1<=y :
        print(xx+1)
        for i in range(n-1):
            print(1)
    elif ((xx+1)**2)*2 +n-2 >=x and 2*(xx+1)+n-2<=y:
        print(xx+1)
        print(xx+1)
        for i in range(n-2):
            print(1)
        
    else:
        print(-1)
else:
    ans=[]
    for i in range(y-n+1,0,-1) :
        if i**2 + n-1 >=x :
            ans.append(i)
            break 
    if len(ans)==0:
        print(-1)
    else:
        print(ans[0])
        for i in range(n-1):
            print(1)
