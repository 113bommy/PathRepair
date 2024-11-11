n,m,d=map(int,input().split())
arr=list(map(int,input().split()))
if((m+1)*(d-1)>=(n-sum(arr))):
    print("YES")
    water=n-sum(arr)
    ans=[]
    co=0
    for i in arr:
        co+=1
        if(water>d-1):
            jump=d-1
            water-=jump

        else:
            jump=water
            water=0
        


        for j in range(jump):
            ans+=[0]
        for j in range(i):
            ans+=[co]
    for i in range(water):
        ans+=[0]
    print(*ans)
else:
    print("NO")
        
        
        