n, k = [int(p) for p in input().split()]
arr = [int(p) for p in input().split()]
count = 0
ans = 1
total = -1
for i in range(len(arr)):
	if arr[i] >= n - k + 1:
		count += arr[i]
		if total != -1:
			ans = (ans*(i-total))%998244353
		total = i
print(count, ans)