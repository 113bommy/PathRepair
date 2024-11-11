n = int(input())
arr = list(map(int, input().split()))
current_count = 0
best_count = 0
current_min = 10**9
current_max = -1
for i in range(n):
	current_min = min(current_min, arr[i])
	current_max = max(current_max, arr[i])
	current_count += 1
	while current_max - current_min > 1:
		j = 0
		k = i - 1
		current_max = arr[k]
		while abs(current_max - arr[i]) <= 1:
			current_max = arr[k]
			j += 1
			k -= 1
		current_max = max(arr[k + 2], arr[i])
		current_min = min(arr[i], current_max)
		current_count = j
	if current_count > best_count:
		best_count = current_count
print(best_count)
