import sys

nums = list(map(int, sys.stdin.readline().split()))

count = 0
while nums[0] < nums[1]:
    if nums[1] % 2 == 0:
        nums[1] /= 2
    else:
        nums[1] += 1
    count += 1
print(count + nums[0] - nums[1])
