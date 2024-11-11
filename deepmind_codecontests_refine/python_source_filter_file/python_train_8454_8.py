t = int(input())
 
while(t>0):
    
    n = int(input())
    
    arr = list(map(int, input().split()))
    
    sum = 0
    ans = 0
    for i in range(n):
        if(arr[i]==0):
            sum+=1
            ans+=1
        else:
            sum+=arr[i]
        
        if(sum==0):
            ans+=1
    
    print(ans)
    t = t-1