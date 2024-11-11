import heapq as hq

n = int(input())
arr = list(map(int,input().split()))
minus = 0
minheap = []
 
dp = [0 for i in range(n)]


k = 0
for i in range(n):
    if arr[i] >= 0:
        dp[i] = arr[i]
        k = i
        break

    else:
        minus += 1


for i in range(k,n):
    dp[i] = dp[i-1] + arr[i]

    if arr[i] < 0:
        hq.heappush(minheap,arr[i])

    if dp[i] < 0:
        while dp[i] < 0:
            a = hq.heappop(minheap)
            minus += 1
            dp[i] -= a

print(n-minus)
