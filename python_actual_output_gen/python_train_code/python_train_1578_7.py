n = int(input())
nums = list(map(int, input().split()))
nums.sort()
print(nums[len(nums)//2])