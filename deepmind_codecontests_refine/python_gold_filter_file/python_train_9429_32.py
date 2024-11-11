n = int(input())
tmp = input().split()
nums = list(int(i) for i in tmp)
nums.sort()
if n < 3:
    print('NO')
    exit(0)
ans = False
for i in range(0, len(nums)-2):
    if nums[i] + nums[i+1] > nums[i+2]:
        ans = True
        break
if ans:
    print('YES')
else:
    print('NO')