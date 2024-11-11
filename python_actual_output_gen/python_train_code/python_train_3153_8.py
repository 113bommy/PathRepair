n = int(input())
arr = list(map(int,input().split()))
ans = 0
for i in range(n):
	# ans = max(ans,arr[i])
	for j in range(i,n):
		# ans = max(ans,arr[i]|arr[j])
		for k in range(j,n):
			ans = max(ans,arr[i]|arr[j]|arr[j])
print(ans)