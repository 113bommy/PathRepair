m, n = input().split()
m, n = int(m) , int(n)

arr = list(input().split())
arr = [int(i) for i in arr]

ans = 0
for i in range(len(arr)):
	if arr[n-1]>0 and arr[i] >= arr[n-1]: ans += 1
	else: break

print(ans)