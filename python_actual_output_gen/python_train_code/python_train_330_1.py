n,m,d=map(int,input().split())
arr=list(map(int,input().split()))
if((m+1)*(d-1)>=(n-sum(arr))):
    print("YES")
    water=n-sum(arr)
    ans=[]
    co=0
    for i in arr:
        co+=1
        if(water>d):
            jump=d
            water-=jump

        else:
            jump=water+1
            water=0
        


        for j in range(jump-1):
            ans+=[0]
        for j in range(i):
            ans+=[co]
    for i in range(water):
        ans+=[0]
    print(*ans)
else:
    print("NO")
        
        
        