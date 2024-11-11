pages = int(input())
nums = list(map(int, input().split()))
n = len(nums)
i = 0
while pages > 0:
	pages -= nums[i%n]
	i+=1
print((i-1)%n+1)