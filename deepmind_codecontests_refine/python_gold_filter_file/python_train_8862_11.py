n=int(input())
a=sorted(list(map(int,input().split())))
arr=[]
for i in range(n-1):
    arr.append(a[i+1]-a[i])
_sum = 0
cnt = 0
maxcnt = 0
    
for i in range(n-1): 

    # If adding current element doesn't 
    # Cross limit add it to current window 
    if ((_sum + arr[i]) <= 5): 
        _sum += arr[i] 
        cnt += 1
        
    # Else, remove first element of current 
    # window and add the current element 
    elif(sum != 0): 
        _sum = _sum - arr[i - cnt] + arr[i] 
        
    # keep track of max length. 
    maxcnt = max(cnt, maxcnt) 
print( maxcnt+1)


