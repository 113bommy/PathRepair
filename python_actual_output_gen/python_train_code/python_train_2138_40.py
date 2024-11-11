from sys import stdin
n = int(stdin.readline())
nums = list(map(int, stdin.readline().rstrip().split(' ')))

nums.sort()

if nums[0] == 1:
    print(-1)
else:
    print(nums[0]-1)