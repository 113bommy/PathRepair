n = int(input())
arr = list(map(int,input().split()))
ans = 0
for i in range(n):
	ans = max(ans,arr[i])
	for j in range(i+1,n):
		ans = max(ans,arr[i]|arr[j])
		for k in range(j+1,n):
			ans = max(ans,arr[i]|arr[j]|arr[k])
print(ans)