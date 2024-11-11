n = int(input())
nums = [input() for i in range(n)]
m = max(nums)
m2 = sorted(nums)[-2]
[print(m) if nums[i] != m else print(m2) for i in range(n)]