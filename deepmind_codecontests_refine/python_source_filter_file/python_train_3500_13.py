[N, K] = map(int,input().split(" "))
nums = list(map(int, input().split(" ")))
if K == 1:
	print(min(nums))
elif K == 2:
	print(min(nums[0], nums[-1]))
else:
	print(max(nums))