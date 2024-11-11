def solve(arr, k):
    
    if len(arr) == 1:
        print(k-arr[0])
        print(k-arr[0])
        return
        
    arr = arr
    ans = 0
    ans_arr = [arr[0]]
    
    for i in range(1,len(arr)):
        tmp = k - (arr[i] + ans_arr[i-1])
        ans += max(0,tmp)
        ans_arr.append(max(0,tmp) + arr[i])
    
    
    print(ans)  
    print(*ans_arr)

n, k = map(int,input().split())
arr = list(map(int,input().split()))
solve(arr,k)

    