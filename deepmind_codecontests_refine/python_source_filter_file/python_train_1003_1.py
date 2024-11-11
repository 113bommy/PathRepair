n = int(input())
nums = [int(x) for x in input().split()]
origin = nums[:]
if n <= 1:
    print("YES")
    raise SystemExit(0)
else:
    for i in range(n-1):
        if nums[i] - nums[i+1] >= 2:
            nums[i] -= 1
            nums[i+1] += 1
        elif nums[i+1] - nums[i] >= 2:
            nums[i] += 1
            nums[i+1] -= 1
        if sorted(origin) != sorted(nums): print("NO")
        else: print("YES")