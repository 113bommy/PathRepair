t = int(input())
length = []
nums = []

for i in range(t):
	length.append(int(input()))
	nums.append(list(map(int, input().split())))

def solve(n, arr):
	if len(set(arr)) == 1:
		print("YES")
	arr.sort()
	for i in range(1,len(arr)):
		if arr[i] - arr[i-1] > 1:
			print("NO")
			return
	print("YES")
	return

# solve(2, [1,2,2])
for i in range(t):
	solve(length[i], nums[i])

