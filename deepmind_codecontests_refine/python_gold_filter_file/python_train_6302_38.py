n = int(input())
nums = ''
for i in range(1, n + 1):
	nums += str(i)
if n < 10:
	print(n)
else:
	print(nums[n - 1])
