
t = int(input())

for test in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    if(n == 1):
        print(arr[0])
    elif(n == 2):
        print(arr[0]+arr[1])
    else:
        ans = 0
        for i in range(n):
            if(i==0 and arr[i+1] < arr[i]):
                ans+=arr[i]-arr[i+1]
                
                arr[i] = arr[i+1]
            elif(i == n-1 and arr[i-1]<arr[i]):
                ans+=arr[i]-arr[i-1]
                
                arr[i]=arr[i-1]
            elif(arr[i] > arr[i-1] and arr[i]>arr[i+1]):
                ans+= arr[i]-max(arr[i-1],arr[i+1])
                
                arr[i] = max(arr[i-1],arr[i+1])
        ans+=arr[0]+arr[-1]
        
        for i in range(1,n-1):
            ans+= abs(arr[i] - arr[i-1])
            
            
        print(ans )
