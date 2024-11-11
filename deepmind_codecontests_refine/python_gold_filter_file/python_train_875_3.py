from math import floor
nums = list(map(int, input().split()))
seq = [1, 1, 2, 7, 4]

min_c = 10000000000
for i in range(len(nums)):
    if floor(nums[i] / seq[i]) < min_c:
        min_c = floor(nums[i] / seq[i])
print(min_c)