n = int(input())
arr = [int(x) for x in input().split()]
m = [0] * (n+1)
ans = [0] * (n+1)
for i in range(n-2,-1,-1):
    m[i] = max(m[i+1], arr[i+1])
    ans[i] = m[i] - arr[i] + 1


print(*ans[:-1])