n = int(input().strip())
arr = list(map(int, input().strip().split()))
ans = 0
limit = 999999999
for i in range(len(arr)-1, -1, -1):
	limit = max(0, min(arr[i], limit-1))
	ans += limit
print(ans)
