for i in range(int(input())):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    if(sum(arr)%k!=0):
        print(len(arr))
    else:
        c=0 
        for i in range(n):
            c+=1 
            if(arr[i]%k):
                break 
        cc=0 
        for j in range(n-1,-1,-1):
            cc+=1 
            if(arr[i]%k):
                break 
        ans=n-min(c,cc)
        if(ans):
            print(ans)
        else:
            print(-1)