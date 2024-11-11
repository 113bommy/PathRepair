n, c = map(int, input().split())
arr = list(map(int, input().split()))

ans = float("-inf")
for i in range(1, n):
    ans = max(ans, arr[i-1] - arr[i])

if ans < 0:
    print(0)
else:
    print(ans - c)
