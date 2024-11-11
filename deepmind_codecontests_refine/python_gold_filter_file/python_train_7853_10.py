n = int(input())
nums = list(map(int, input().split()))
nums.sort()
dif = nums[-1] - nums[0]
cnt = 0
if dif == 0:
    cnt = len(nums) * (len(nums)-1) // 2
else:
    cmin = 0
    for i in range(len(nums)):
        if nums[i] == nums[0]:
            cmin+=1
        else:
            break
    cmax = 0
    for i in range(len(nums)):
        if nums[-i-1] == nums[-1]:
            cmax+=1
        else:
            break
    cnt = cmin*cmax
print(str(dif) + " " + str(cnt))