n = int(input())
tmp = input().split()
nums = list(int(i) for i in tmp)
nums.sort()
if n < 3:
    print('NO')
    exit(0)
ans = False
for i in range(3, len(nums)):
    if nums[i-2] + nums[i-1] > nums[i]:
        ans = True
        break
if ans:
    print('YES')
else:
    print('NO')