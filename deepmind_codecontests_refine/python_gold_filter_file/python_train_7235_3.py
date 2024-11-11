n = int(input())

arr = [int(x) for x in input().split()]
ans = [0] * n

ans[0] = abs(arr[0])
for i in range(1, n):
    ans[i] = ans[i - 1] + abs(arr[i] - arr[i - 1])
    
print(ans[n - 1])