from bisect import bisect_left
n, u = map(int, input().split())
arr = [int(x) for x  in input().split()]
ans = -1
for i in range(n-2):
    bi = bisect_left(arr, arr[i] + u)
    if bi == n: bi -= 1
    if bi == i+1: continue
    if arr[bi] - u > arr[i]: bi -= 1
    if i == bi or i+1 == bi: continue
    #print(arr[i], arr[i+1], arr[bi])
    ans = max(ans, (arr[bi] - arr[i+1])/(arr[bi] - arr[i]))
print(ans)