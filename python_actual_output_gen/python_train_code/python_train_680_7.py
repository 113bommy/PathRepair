def calcdifs(nums):
    difs = []
    for i in range(len(nums)-1):
        difs.append(nums[i+1]-nums[i])
    return sum(difs)

input()
nums = sorted([int(x) for x in input().split()])
allvalues = []
for i, ii in enumerate(nums):
    for j, jj in enumerate(nums):
        if i != j:
            nums2 = nums.copy()
            nums2.remove(ii)
            nums2.remove(jj)
            allvalues.append(calcdifs(nums2))
print(min(allvalues))