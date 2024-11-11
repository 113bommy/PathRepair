jj = input()
numsLine = input()
nums = numsLine.split()
nums =list(map(int,nums))
list.sort(nums)
if len(nums) == 1:
    print("NO")
else:
    if nums[0] != nums[1]:
        print(nums[1])
    else:
        good = False
        for x in nums:
            if x != nums[0]:
                print(x)
                good = True
                break
        if not good:
            print("No")
