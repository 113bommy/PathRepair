def proA(arr,m):
    ans=0
    for j in range(len(arr)):
        
        for i in range(len(arr)):
            if(arr[i]<=0):
                continue
            arr[i]-=m
            ans=i+1
    print(ans)
n,m=list(map(int,input().split()))
arr=list(map(int,input().split()))
proA(arr,m)