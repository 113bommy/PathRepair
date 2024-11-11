def minSum(arr, n, k): 
    if (n < k):
        return -1
    res = 0
    index = 0
    for i in range(k):
        res += arr[i]
    curr_sum = res
    for i in range(k, n):
        curr_sum += arr[i] - arr[i-k]
        if res > curr_sum:
            res = curr_sum
            index = i-k+1
    return index+1

n,k = map(int,input().split())
l = list(map(int,input().split()))
print(minSum(l, n, k)) 