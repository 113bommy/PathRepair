n, d = [int(j) for j in input().split()]
nums = [int(j) for j in input().split()]
count = 0
for j in range(1, n):
    if nums[j] <= nums[j - 1]:
        f = int((nums[j - 1] - nums[j]) / d + 1)
        count += f
        nums[j] += f * 2
print(count)
